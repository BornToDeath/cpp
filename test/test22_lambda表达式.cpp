//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>

void func1() {
    auto p1 = std::make_unique<int>(10);
    // 表达式捕获
    auto add = [v1 = 1, v2 = std::move(p1)](int x, int y) {
        return x + y + v1 + *v2;
    };
    std::cout << add(2, 3) << std::endl;
}

int main() {
    func1();
    return 0;
}