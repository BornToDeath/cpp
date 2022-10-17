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
#include <map>

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

void test04();

void test05();

void test06();

int main() {
    test06();
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

class Person {
public:
    // 无参构造
    Person() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // 有参构造
    Person(int num) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // 析构
    ~Person() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // 拷贝构造
    Person(const Person &obj) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // 拷贝赋值
    Person &operator=(const Person &obj) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }

    // 移动构造
    Person(Person &&obj) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    // 移动赋值
    Person &operator=(Person &&obj) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
};

/**
 * 测试 vector 扩容
 */
void test04() {
    std::vector<Person> _vec;
    std::cout << "=====Start" << std::endl;
    Person p1;

    std::cout << "=====1" << std::endl;
    _vec.push_back(p1);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====2" << std::endl;
    _vec.push_back(p1);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====3" << std::endl;
    _vec.push_back(p1);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====4" << std::endl;
    _vec.push_back(p1);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====5" << std::endl;
    _vec.push_back(p1);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====6" << std::endl;
    _vec.push_back(p1);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====7" << std::endl;
    _vec.emplace_back(std::move(p1));
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====8" << std::endl;
    _vec.emplace_back(5);
    std::cout << "vector size = " << _vec.capacity() << std::endl;

    std::cout << "=====End" << std::endl;
}

/**
 * 测试 shrink_to_fit() 方法
 */
void test05() {
    std::vector<int> nums;
    std::cout << sizeof(nums) << std::endl;

    nums.push_back(1);
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;

    nums.push_back(2);
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;

    nums.push_back(3);
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;

    nums.push_back(4);
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;

    nums.push_back(5);
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;

    nums.clear();
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;

    nums.shrink_to_fit();
    std::cout << nums.size() << ", " << nums.capacity() << std::endl;
}

void test06() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.push_back(i + 1);
    }

    for (int &i : v) {
        std::cout << i << ": " << &i << std::endl;
    }
    std::cout << "[1]-------------" << std::endl;

    for (std::vector<int>::iterator it = v.begin(); it != v.end();) {
        it = v.erase(it);  // 推荐写法
//        v.erase(it++);  // 有崩溃
    }
    std::cout << "[2]-------------" << std::endl;

    std::map<int, int> _map = {
            {1, 1},
            {2, 2},
            {3, 3},
            {4, 4},
            {5, 5},
    };

    for (auto &e: _map) {
        std::cout << "[" << e.first << ", " << e.second << "]" << ": " << &e << std::endl;
    }

    auto it = _map.begin();
    while (it != _map.end()) {
        it = _map.erase(it);  // 推荐写法
//        _map.erase(it++);  // 不会崩溃
//        it++;  // 会崩溃
    }

    std::cout << _map.size() << std::endl;
    std::cout << "End" << std::endl;
}