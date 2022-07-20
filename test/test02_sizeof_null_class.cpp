//
// Created by lixiaoqing on 2021/11/2.
//

#include <iostream>

void test01();

void test02();

void test03() {
    class AA {
        virtual void func() {};
    };

    // 虚继承，子类没有自定义虚函数
    class BB : virtual public AA {

    };

    // 虚继承，子类有自定义虚函数
    class CC : virtual public AA {
        virtual void funcCC() {};
    };

    std::cout << sizeof(AA) << std::endl;  // 8
    std::cout << sizeof(BB) << std::endl;  // 8
    std::cout << sizeof(CC) << std::endl;  // 8
}

int main() {
    test03();
    return 0;
}

void test02() {
    class AA {
    public:
        virtual void func1();
    };

    class AA1 : public AA {

    };

    std::cout << sizeof(AA) << std::endl;   // 8
    std::cout << sizeof(AA1) << std::endl;  // 8
}

class A {

};

class B : public A {

};

class C : virtual public A {

};

class D : public A, public B {

};

class E : virtual public A, virtual public B {

};

class F : public E {

};

void test01() {
    std::cout << sizeof(A) << std::endl;  // 1
    std::cout << sizeof(B) << std::endl;  // 1
    std::cout << sizeof(C) << std::endl;  // 8
    std::cout << sizeof(D) << std::endl;  // 2
    std::cout << sizeof(E) << std::endl;  // 16
    std::cout << sizeof(F) << std::endl;  // 16
}