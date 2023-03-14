//
// Created by lixiaoqing on 2023/3/10.
//

#include <iostream>
#include <vector>


// 返回右值
auto at1(std::vector<int> &arr, int pos) {  // c++11
    return arr[pos];
}

// 返回左值
auto at2(std::vector<int> &arr, int pos) -> decltype(arr[pos]) {  // c++11
    return arr[pos];
}

// 返回左值
decltype(auto) at3(std::vector<int> &arr, int pos) {  // c++14
    return arr[pos];
}

void test01() {
    std::vector<int> arr = {1, 2, 3, 4, 5};

//    at1(arr, 3) = 10;   // error
    std::cout << arr[3] << std::endl;

    at2(arr, 3) = 20;  // ok
    std::cout << arr[3] << std::endl;

    at3(arr, 3) = 30;  // ok
    std::cout << arr[3] << std::endl;
}

int main() {
    test01();
    return 0;
}