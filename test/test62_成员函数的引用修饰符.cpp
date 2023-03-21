//
// Created by lixiaoqing on 2023/3/14.
//

#include <iostream>
#include <vector>
#include <iterator>

class A {
public:
    void print() &{  // 只被左值调用
        std::cout << "left" << std::endl;
    }

    void print() &&{  // 只被右值调用
        std::cout << "right" << std::endl;
    }
};

void test01() {
    A a;
    a.print();     // Hello
    A().print();   // World
}

int main() {
    test01();
    return 0;
}