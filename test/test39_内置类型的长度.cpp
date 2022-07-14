//
// Created by lixiaoqing on 2022/7/14.
//

#include <iostream>

void test01() {
    auto num = std::numeric_limits<double>::max();
    int count = 0;
    while (num) {
        ++count;
        num /= 2;
    }
    std::cout << count << std::endl;
}

int main() {
//    test01();
    std::cout << sizeof(long double) << std::endl;
    std::cout << std::numeric_limits<double>::min() << std::endl;
    std::cout << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::numeric_limits<unsigned long long>::min() << std::endl;
    std::cout << std::numeric_limits<unsigned long long>::max() << std::endl;
    std::cout << pow(2, 64) << std::endl;
    std::cout << std::numeric_limits<long double>::min() << std::endl;
    std::cout << std::numeric_limits<long double>::max() << std::endl;
    std::cout << std::numeric_limits<long long int>::min() << std::endl;
    std::cout << std::numeric_limits<long long int>::max() << std::endl;
    std::cout << pow(2, 128) << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl;
    return 0;
}