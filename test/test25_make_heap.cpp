//
// Created by lixiaoqing on 2022/4/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

void test01() {
    std::vector<int> v = {67, 9, 7, 5, 43, 6, 7, 8};
    print(v);

    std::cout << std::boolalpha;
    std::cout << std::is_heap(v.begin(), v.end()) << std::endl;

    std::make_heap(v.begin(), v.end());
    print(v);
    std::cout << std::is_heap(v.begin(), v.end()) << std::endl;

    std::pop_heap(v.begin(), v.end());
    print(v);

    std::make_heap(v.begin(), v.end(), std::greater<>());
    print(v);
}

int main() {
    test01();
    return 0;
}