//
// Created by lixiaoqing on 2021/11/2.
//

#include <iostream>

void test01();

int main() {
    test01();
    return 0;
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

class F: public E {

};

void test01() {
    std::cout << sizeof(A) << std::endl;  // 1
    std::cout << sizeof(B) << std::endl;  // 1
    std::cout << sizeof(C) << std::endl;  // 8
    std::cout << sizeof(D) << std::endl;  // 2
    std::cout << sizeof(E) << std::endl;  // 16
    std::cout << sizeof(F) << std::endl;  // 16
}