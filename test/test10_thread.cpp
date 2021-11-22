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
    t1.join();
    std::cout << t1.joinable() << std::endl;
    std::cout << std::this_thread::get_id() << std::endl;
    std::cout << std::thread::hardware_concurrency() << std::endl;
}