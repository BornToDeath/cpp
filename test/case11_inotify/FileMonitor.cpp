//
// Created by lixiaoqing on 2022/7/12.
//

#include <sys/inotify.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <cstdio>
#include <iostream>
#include "FileMonitor.h"

#define log(format, ...) { \
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());   \
    char buf[64];                                                                        \
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));               \
    printf("%s | %llu | ", buf, std::this_thread::get_id());                             \
    printf(format, ##__VA_ARGS__);                                                       \
    printf("\n"); }

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

void FileMonitor::startWatch(const std::string &path) {
    log("Ready to watch...");

    // inotify 初始化
    inotify_fd = inotify_init();
    if (!addWatch(path)) {
        return;
    }

    // 创建一个 epoll 句柄
    log("epoll_create");
    int epfd = epoll_create(256);
    struct epoll_event ev;
    ev.data.fd = inotify_fd;        // 设置要处理的事件相关的文件描述符
    ev.events = EPOLLIN | EPOLLET;  // 设置要处理的事件类型

    // 注册 epoll 事件
    log("epoll_ctl");
    epoll_ctl(epfd, EPOLL_CTL_ADD, inotify_fd, &ev);

    // 循环监听事件
    char buffer[BUF_LEN];
    struct epoll_event events[20];  // 存储从内核得到的事件集合
    while (!isStopped) {
        log("epoll_wait...");
        // 等待事件发生。返回需要处理的事件数目
        int nfds = epoll_wait(epfd, events, 20, 500);
        log("Event count: %d", nfds);
        for (int i = 0; i < nfds; ++i) {
            /**
             * epoll_wait 会一直阻塞直到下面2种情况：
             *   1. 一个文件描述符触发了事件。
             *   2. 被一个信号处理函数打断，或者 timeout 超时。
             * 所以下面需要对 fd 进行过滤，判断是否是我们需要的 fd 产生了事件
             */
            if (events[i].data.fd != inotify_fd) {
                log("Other event, fd=%d", events[i].data.fd);
                continue;
            }
            long length = read(inotify_fd, buffer, BUF_LEN);
            if (length < 0) {
                perror("Read failed");
            }
            log("Read length: %ld", length);
            int pos = 0;
            int count = 0;
            while (pos < length) {
                struct inotify_event *event = (struct inotify_event *) &buffer[pos];
                log("[%d]event->len=%u, event->mask=%#X, EVENT_SIZE=%lu", ++count, event->len, event->mask, EVENT_SIZE);
                if (event->len) {
                    if (event->mask & IN_CREATE) {
                        log("CREATE: %s", event->name);
                    } else if (event->mask & IN_DELETE) {
                        log("DELETE: %s", event->name);
                    } else if (event->mask & IN_MODIFY) {
                        log("MODIFY: %s", event->name);
                    } else if (event->mask & IN_OPEN) {
                        log("OPEN: %s", event->name);
                    } else if (event->mask & IN_CLOSE) {
                        log("CLOSE: %s", event->name);
                    } else {
                        log("Unknown event, mask=%u", event->mask);
                    }
                }
                pos += EVENT_SIZE + event->len;
            }
        }
    }
    log("Stop inotify");
    for (auto &ele: watchDesc2Name) {
        inotify_rm_watch(inotify_fd, ele.first);
    }
    close(epfd);
    close(inotify_fd);
}

void FileMonitor::stopWatch() {
    isStopped = true;
}

bool FileMonitor::addWatch(const std::string &path) {
    // TODO 需要对文件（夹）是否存在进行判断
    // 监听指定目录下的修改、创建、删除事件
    int wd = inotify_add_watch(inotify_fd, path.c_str(), IN_MODIFY | IN_CREATE | IN_DELETE);
//    int wd = inotify_add_watch(inotify_fd, path.c_str(), IN_ALL_EVENTS);
    if (wd < 0) {
        log("inotify_add_watch failed: %s", path.c_str());
        return false;
    }
    log("Add watch: %s", path.c_str());
    watchDesc2Name[wd] = path;
    return true;
}