//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr) {
    for (const auto ele: arr) {
        std::cout << ele << ", ";
    }
    std::cout << std::endl;
}

class A {
public:
    /**
     * 初始化列表构造函数
     * @param list
     */
    A(std::initializer_list<int> list) {
        for (const auto ele: list) {
            arr.emplace_back(ele);
        }
    }

    void init(std::initializer_list<int> list) {
        for (const auto ele: list) {
            arr.emplace_back(ele);
        }
    }

public:
    std::vector<int> arr;
};

int main() {
    A a = {1, 2, 3, 4, 5};
    printArray(a.arr);
    a.init({6, 7, 8, 9, 10});
    printArray(a.arr);

    A b{1, 3, 5, 7, 9};
    printArray(b.arr);
    return 0;
}