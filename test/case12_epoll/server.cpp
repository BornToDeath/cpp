//
// Created by lixiaoqing on 2022/7/18.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <string>
#include <iostream>

// socket 最大连接数
#define SOCKET_COUNT (64)

// epoll 监听的描述符的最大数量
#define EPOLL_COUNT (100)

int main() {

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket error");
        exit(1);
    }

    // 设置端口复用
    int opt = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 监听本地所有IP
    int ret = bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    ret = listen(socket_fd, SOCKET_COUNT);
    if (ret == -1) {
        perror("listen error");
        exit(1);
    }

    int epoll_fd = epoll_create(EPOLL_COUNT);
    if (epoll_fd == -1) {
        perror("epoll_create error");
        exit(1);
    }

    struct epoll_event ev;
    ev.data.fd = socket_fd;
    ev.events = EPOLLIN;  // 检测 socket_fd 读缓冲区是否有数据
    ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &ev);
    if (ret == -1) {
        perror("epoll_ctl error");
        exit(1);
    }

    struct epoll_event evs[1024];
    int size = sizeof(evs) / sizeof(struct epoll_event);

    // 持续检测
    for (;;) {
        printf("epoll_wait ...\n");
        int num = epoll_wait(epoll_fd, evs, size, -1);
        for (int i = 0; i < num; ++i) {
            int cur_fd = evs[i].data.fd;
            if (cur_fd == socket_fd) {
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int new_fd = accept(socket_fd, (struct sockaddr *) &client_addr, &client_addr_len);
                printf("new client: %d, IP: %s:%d\n", new_fd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

                ev.data.fd = new_fd;
                ev.events = EPOLLIN;
                ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_fd, &ev);
                if (ret == -1) {
                    perror("epoll_ctl accept error");
                    continue;
                }
            } else {
                char buf[1024]{};
                int len = recv(cur_fd, buf, sizeof(buf), 0);
                if (len == 0) {
                    printf("客户端 %d 已经断开了连接\n", cur_fd);
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, cur_fd, NULL);
                    close(cur_fd);
                } else if (len > 0) {
                    printf("客户端说: %s\n", buf);
                    std::string text;
//                    getline(std::cin, text);  // 等待输入
                    text.insert(0, "[吴彦祖] 啊对对对");
                    text.push_back('\n');
                    send(cur_fd, text.c_str(), text.length(), 0);
                } else {
                    perror("socket recv error");
                    continue;
                }
            }
        }
    }

    // 关闭 socket
    close(epoll_fd);
    close(socket_fd);

    return 0;
}