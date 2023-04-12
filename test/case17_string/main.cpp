//
// Created by lixiaoqing on 2023/4/12.
//

#include <iostream>
#include "String.h"

void test01() {
    String s1("Hello");
    std::cout << s1.c_str() << std::endl;
    printf("%p\n", s1.c_str());

    String s2("World");
    std::cout << s2.c_str() << std::endl;
    printf("%p\n", s2.c_str());

    s2 = s1;
    std::cout << s1.c_str() << std::endl;
    std::cout << s2.c_str() << std::endl;
    printf("%p\n", s1.c_str());
    printf("%p\n", s2.c_str());
}

void test02() {
    String s1("Hello");
    printf("%p\n", s1.c_str());

    auto s2 = std::move(s1);
    printf("%p\n", s1.c_str());
    printf("%p\n", s2.c_str());
}

int main() {
    test01();
    return 0;
}