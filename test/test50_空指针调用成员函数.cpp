//
// Created by lixiaoqing on 2022/10/10.
//

#include <iostream>

class A {
public:
    void print1() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << this << std::endl;
//        std::cout << num << std::endl;  // 如果取消注释，则程序崩溃
    }

    virtual void print2() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << this << std::endl;
    }

public:
    int num{10};
};

int main() {
    A *a = nullptr;
    a->print1();  // 没问题
    a->print2();  // 有问题，程序崩溃
    return 0;
}