//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    // C++17支持如下声明变量
    if (auto it = std::find(arr.begin(), arr.end(), 1); it != arr.end()) {
        std::cout << *it << std::endl;
    }
    return 0;
}