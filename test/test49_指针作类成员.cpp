//
// Created by lixiaoqing on 2022/9/28.
//

/**
 * 结论：类成员如果是指针类型，该成员如果不执行默认初始化，则为野指针，在运行时如果使用该指针变量的成员时，会导致进程崩溃。
 */

#include <iostream>

class Base {
public:
    int num;
};

class A {
    A() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~A() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:
    Base *base;
};

class B {
public:
    B() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~B() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:
    A *a;
};


int main() {
    B b;
    printf("b.a=%p\n", b.a);
    if (b.a == nullptr) {
        printf("b.a is nullptr\n");
    } else {
        printf("b.a is not nullptr\n");
        printf("b.a->base=%p\n", b.a->base);
        std::cout << b.a->base->num << std::endl;  // 有崩溃
    }
    return 0;
}