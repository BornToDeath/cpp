//
// Created by lixiaoqing on 2022/1/14.
//

#include <iostream>
#include <algorithm>
#include <vector>

void printArray(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) {
        std::cout << num << ", ";
    });
    std::cout << std::endl;
}

void test01() {
    std::vector<int> nums = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10};
    std::sort(nums.begin(), nums.end(), [](int num1, int num2) {
        return num1 <= num2;  // 有问题！在mac上会出现崩溃，但是在linux上不会。改成 < 即可。":q
    });
    printArray(nums);
}

void test02() {
    std::vector<int> vec{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // 全是一样的元素，且必须超过16个元素
    std::sort(vec.begin(), vec.end(), [](const int &lhs, const int &rhs) {
        return lhs <= rhs;  // BUG，修改为: return lhs < rhs; 才行
    });
    printArray(vec);
}

void test03() {
    std::vector<int> nums = {7, 5, 8};
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a - b;
    });
    printArray(nums);
}


int main() {
    std::cout << "==============Before test==============" << std::endl;
    test01();
    std::cout << "==============After test==============" << std::endl;
    return 0;
}