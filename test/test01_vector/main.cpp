//
// Created by lixiaoqing on 2021/10/28.
//

/**
 * 目的：测试 std::vector 中的元素是保存在栈上还是堆上。
 * 结果：堆上。
 */

#include <iostream>
#include <vector>

class A {
public:
    std::vector<int> nums;
};

void test01() {
    std::vector<int> v;
    std::cout << sizeof(v) << std::endl;  // 24

    A a;
    std::cout << sizeof(a) << std::endl;  // 24

    a.nums.emplace_back(10);
    std::cout << sizeof(a) << std::endl;  // 24

    a.nums.emplace_back(10);
    std::cout << sizeof(a) << std::endl;  // 24

    a.nums.emplace_back(10);
    std::cout << sizeof(a) << std::endl;  // 24

    a.nums.emplace_back(10);
    std::cout << sizeof(a) << std::endl;  // 24
}

int main() {
    test01();
    return 0;
}