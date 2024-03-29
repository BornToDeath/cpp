//
// Created by lixiaoqing on 2022/7/12.
//

#include <sys/inotify.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

bool isQuited = false;

void quit() {
    isQuited = true;
}

int main(int argc, char *argv[]) {

    // inotify 初始化
    int fd = inotify_init();
    int wd = inotify_add_watch(fd, "/home/cc/tmp/", IN_MODIFY | IN_CREATE | IN_DELETE);  // 监听指定目录下的修改、创建、删除事件

    // 创建一个 epoll 句柄
    int epfd = epoll_create(256);
    struct epoll_event ev;
    ev.data.fd = fd;                // 设置要处理的事件相关的文件描述符
    ev.events = EPOLLIN | EPOLLET;  // 设置要处理的事件类型

    // 注册 epoll 事件
    epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);

    // 循环监听事件
    char buffer[BUF_LEN];
    struct epoll_event events[20];  // 存储从内核得到的事件集合
    while (isQuited) {
        // 等待事件发生。返回需要处理的事件数目
        int nfds = epoll_wait(epfd, events, 20, 500);
        for (int i = 0; i < nfds; ++i) {
            /**
             * epoll_wait 会一直阻塞直到下面2种情况：
             *   1. 一个文件描述符触发了事件。
             *   2. 被一个信号处理函数打断，或者 timeout 超时。
             * 所以下面需要对 fd 进行过滤，判断是否是我们需要的 fd 产生了事件
             */
            if (events[i].data.fd != fd) {
                continue;
            }
            int length = read(fd, buffer, BUF_LEN);
            if (length < 0) {
                perror("read");
            }
            int pos = 0;
            while (pos < length) {
                struct inotify_event *event = (struct inotify_event *) &buffer[pos];
                if (event->len) {
                    if (event->mask & IN_CREATE) {
                        if (event->mask & IN_ISDIR) {
                            printf("The directory %s was created.\n", event->name);
                        } else {
                            printf("The file %s was created.\n", event->name);
                        }
                    } else if (event->mask & IN_DELETE) {
                        if (event->mask & IN_ISDIR) {
                            printf("The directory %s was deleted.\n", event->name);
                        } else {
                            printf("The file %s was deleted.\n", event->name);
                        }
                    } else if (event->mask & IN_MODIFY) {
                        if (event->mask & IN_ISDIR) {
                            printf("The directory %s was modified.\n", event->name);
                        } else {
                            printf("The file %s was modified.\n", event->name);
                        }
                    }
                }
                pos += EVENT_SIZE + event->len;
            }
        }
    }

    inotify_rm_watch(fd, wd);
    close(epfd);
    close(fd);
    return 0;
}