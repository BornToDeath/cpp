//
// Created by lixiaoqing on 2021/10/28.
//

/**
 * 测试1：
 *   目的：测试 std::vector 中的元素是保存在栈上还是堆上。
 *   结果：堆上。
 *
 * 测试2：
 *   目的：测试 std::stack 中的元素是保存在栈上还是堆上。
 *   结果：堆上。
 */

#include <iostream>
#include <vector>
#include <stack>

class A {
public:
    std::vector<int> nums;
};

class B {
public:
    std::stack<int> stack;
};

void test01();

void test02();

void test03();

int main() {
    test03();
    return 0;
}

void test03() {
    std::string name = "lixiaoqing";
    std::vector<char> vec(name.length(), 0);
    memcpy(vec.data(), name.c_str(), name.length());
    name = "fighting!";
}

void test02() {
    /**
     * 测试 std::stack
     */
    std::stack<int> stack;
    std::cout << sizeof(stack) << std::endl;

    B b;
    std::cout << sizeof(b) << std::endl;

    b.stack.push(10);
    std::cout << sizeof(b) << std::endl;

    b.stack.push(10);
    std::cout << sizeof(b) << std::endl;

    b.stack.push(10);
    std::cout << sizeof(b) << std::endl;

    b.stack.push(10);
    std::cout << sizeof(b) << std::endl;

    /**
        输出结果：
        48
        48
        48
        48
        48
        48
     */
}

void test01() {
    /**
     * 测试 std::vector
     */
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