//
// Created by lixiaoqing on 2022/4/25.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <csignal>
#include <unistd.h>

void log(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

void signal_handler(int signo) {
    log("终止程序");
    exit(1);
};

void start_server() {
    // 1. socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. bind
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9991);
    int ret = bind(sock, (struct sockaddr *) &addr, sizeof(addr));
    if (ret < 0) {
        log("bind failed, ret=%d", ret);
        return;
    }

    // 3. listen
    ret = listen(sock, 10);
    if (ret < 0) {
        log("listen failed, ret=%d", ret);
        return;
    }

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    while (true) {
        // 4. accept
        int client_fd = accept(sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd < 0) {
            log("accept failed, client_fd=%d", client_fd);
            continue;
        }

        char ip_str[16]{};
        // 将地址从网络字节序转换为点分十进制
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip_str, sizeof(ip_str));
        log("connected from %s:%d", ip_str, client_addr.sin_port);

        // 5. write
        static int count = 1;
        std::string msg = "来自远方的问候" + std::to_string(count++);
        auto size = msg.length();
        size_t len = write(client_fd, msg.c_str(), size);
        if (len != size) {
            log("write failed.");
            continue;
        }
        log("  send:[%s], len=%d", msg.c_str(), len);

        char buf[1024]{};
        auto recv_len = recv(client_fd, buf, sizeof(buf), 0);
        if (recv_len > 0) {
            log("  recv:[%s], len=%d", buf, recv_len);
        }

        // 6. close client
        close(client_fd);
    }

    // 7. close server
    close(sock);
}

int main() {
    signal(SIGINT, signal_handler);
    start_server();
    return 0;
}