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

void start_client() {
    // 1. socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. connect
    struct sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9991);
    int ret = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret < 0) {
        log("connect failed");
        exit(1);
    }
    log("connected!");

    // 3. read
    char buf[1024];
    auto read_size = read(sock, buf, sizeof(buf));
    if (read_size > 0) {
        log("receive:[%s], len=%d", buf, read_size);
    }

    const std::string msg = "我喜欢你";
    const auto msg_len = msg.length();
    auto len = send(sock, msg.c_str(), msg_len, 0);
    if (len != msg_len) {
        log("send failed.");
        exit(1);
    }
    log("send:[%s], len=%d", msg.c_str(), len);

    // 4. close
    close(sock);
}

int main() {
    start_client();
    return 0;
}
