//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, double, std::string> func() {
    return std::make_tuple(10, 3.14, "Hello");
}

int main() {
    // C++17提供结构化绑定，可以更方便的对tuple进行解析
    auto[x, y, z] = func();
    std::cout << x << ", "
              << y << ", "
              << z << std::endl;
    return 0;
}