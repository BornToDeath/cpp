//
// Created by lixiaoqing on 2022/6/9.
//

#include <iostream>
#include <functional>
#include <string>

namespace Test {
    void test01() {
        int x = 10;
        std::cout << std::boolalpha << std::is_same<int &, decltype(std::ref(x))>::value << std::endl;
        auto r = std::ref(x);
        std::cout << r.get() << std::endl;
        x = 20;
        std::cout << r.get() << std::endl;
        int &r2 = std::ref(x);
        std::cout << r2 << std::endl;
        x = 30;
        std::cout << r << ", " << r2 << std::endl;
    }
}

int main() {
    Test::test01();
    return 0;
}