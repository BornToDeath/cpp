//
// Created by lixiaoqing on 2021/11/16.
//

#include <iostream>
#include <thread>

void test01();

int main() {
    test01();
    return 0;
}

void test01() {
    std::cout << std::boolalpha;
    std::thread t1([]() {
        std::cout << "Thread1 正在执行" << std::endl;
    });
    std::cout << t1.joinable() << std::endl;
    t1.detach();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (t1.joinable()) {
        std::cout << "joinable=true" << std::endl;
    } else {
        std::cout << "joinable=false" << std::endl;
    }

    // 线程ID
    std::cout << "[1]TID=" << std::this_thread::get_id() << std::endl;  // 16进制
    printf("[2]TID=%llu\n", std::this_thread::get_id());  // 10进制

    // 获取硬件支持的线程并发数
    std::cout << "线程并发数=" << std::thread::hardware_concurrency() << std::endl;
}