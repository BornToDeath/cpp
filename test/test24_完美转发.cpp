//
// Created by lixiaoqing on 2022/4/21.
//

#include <iostream>

void func(int &num) {
    std::cout << "左值引用" << std::endl;
}

void func(int &&num) {
    std::cout << "右值引用" << std::endl;
}

void pass(int &&num) {
    func(num);
    func(std::move(num));
    func(std::forward<int>(num));
}

void test01() {
    int num = 10;
//    pass(num);
    func(10);
    pass(10);
}

int main() {
    test01();
    return 0;
}