//
// Created by lixiaoqing on 2023/2/6.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class A {
public:
    A() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

    ~A() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

public:
    int num{0};
};

// 虚继承
class B : virtual public A {
public:
    B() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

    ~B() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

//public:
//    int num{10};
};

// 虚继承
class C : virtual public A {
public:
    C() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

    ~C() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

//public:
//    int num{20};
};

class D : public B, public C {
public:
    D(int num) {
        this->num = num;  // 如果不是虚继承，此时会出现二义性，必须指明哪一个父类的成员: this->B::num = num;
        printf("%s\n", __PRETTY_FUNCTION__);
    }

    ~D() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

//public:
//    int num{30};
};

void test01() {
    std::cout << "A: " << sizeof(A) << std::endl;
    std::cout << "B: " << sizeof(B) << std::endl;
    std::cout << "C: " << sizeof(C) << std::endl;
    std::cout << "D: " << sizeof(D) << std::endl;
}

void test02() {
    std::cout << "---------------" << std::endl;
    {
        B b;
        std::cout << "b.num: " << b.num << std::endl;
        std::cout << "b.A::num: " << b.A::num << std::endl;
    }
    std::cout << "---------------" << std::endl;
    {
        D d(100);
        std::cout << "d.num: " << d.num << std::endl;
        std::cout << "d.B::num: " << d.B::num << std::endl;
        std::cout << "d.C::num: " << d.C::num << std::endl;
    }
}

int main() {
    test01();
    test02();
    return 0;
}