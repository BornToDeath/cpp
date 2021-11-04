//
// Created by lixiaoqing on 2021/11/4.
//

#include <iostream>

/**
 * 结论：
 *
 * 【1】当使用 new 关键字创建对象时，其实际上进行了如下操作：
 *  1. 调用 operator new() 申请内存
 *  2. 调用类 A 的构造函数来构造对象
 *  3. 对象构造完成后，将对象的地址赋值给 ptr
 *
 * 【2】当使用 delete 关键字释放对象时，其实际上进行了如下操作：
 *  1. 调用对象的析构函数
 *  2. 调用 operator delete() 释放内存空间。
 *
 * 注：
 *  1. 可通过这个网站(https://godbolt.org/)查看详细的汇编过程
 */

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

void test01() {
    auto ptr = new A();
    std::cout << sizeof(A) << std::endl;
    delete ptr;
    ptr = nullptr;
    delete ptr;
}

int main() {
    test01();
    return 0;
}