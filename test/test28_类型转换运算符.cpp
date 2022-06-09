//
// Created by lixiaoqing on 2022/6/9.
//

#include <iostream>
#include <vector>

class A {
public:
    // 隐式类型转换运算符
    operator int() const {
        return 1;
    }
};

class B {
public:
    // 显示类型转换运算符
    explicit operator int() const {
        return 2;
    }
};

void test01() {
    A a;
    std::cout << a + 10 << std::endl;  // 隐式类型转换

    B b;
//    std::cout << b + 10 << std::endl;  // error
    std::cout << static_cast<int>(b) + 10 << std::endl;  // 显示类型转换
}

void test02() {
//    std::vector<int&> arr;  // compile error
    std::vector<std::reference_wrapper<int>> arr;
}

int main() {
    test01();
    return 0;
}