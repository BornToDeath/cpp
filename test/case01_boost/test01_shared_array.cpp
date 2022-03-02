//
// Created by lixiaoqing on 2021/11/16.
//

#include <iostream>
#include "boost/shared_array.hpp"

void test01() {
    boost::shared_array<int> arr1(new int[2]);
    boost::shared_array<int> arr2(arr1);

    arr1[0] = 10;
    arr1[1] = 20;

    assert(arr1[0] != arr1[1]);
    std::cout << arr1[0] << std::endl;
    std::cout << arr1[1] << std::endl;
    std::cout << arr2[0] << std::endl;
    std::cout << arr2[1] << std::endl;
}

int main() {
    test01();
    return 0;
}