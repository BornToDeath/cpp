//
// Created by lixiaoqing on 2021/12/24.
//

#include <iostream>
#include <string>

void test01() {
    union A {
    public:
        A() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        ~A() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        int num;
        std::string name;
        double height;
    };

    A a;
    std::cout << sizeof(a) << std::endl;

    a.num = 10;
    std::cout << sizeof(a) << std::endl;
    std::cout << "num: " << a.num << std::endl;
    std::cout << "height: " << a.height << std::endl;

//    a.name = "I love you three thousand times.";
    std::cout << sizeof(a) << std::endl;

    a.height = 1.75;
    std::cout << sizeof(a) << std::endl;
    std::cout << "num: " << a.num << std::endl;
    std::cout << "height: " << a.height << std::endl;
}

int main() {
    test01();
    return 0;
}