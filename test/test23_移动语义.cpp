//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>
#include <vector>
#include <string>

class A {
public:
    int *pointer;

    A() : pointer(new int(1)) {
        std::cout << "构造" << pointer << std::endl;
    }

    A(A &a) : pointer(new int(*a.pointer)) {
        std::cout << "拷贝" << pointer << std::endl;
    } // 无意义的对象拷贝

    A(A &&a) : pointer(a.pointer) {
        a.pointer = nullptr;
        std::cout << "移动" << pointer << std::endl;
    }

    A &operator=(A &&a) {
        std::cout << "移动赋值" << std::endl;
        pointer = a.pointer;
        a.pointer = nullptr;
        return *this;
    }

    ~A() {
        std::cout << "析构" << pointer << std::endl;
        delete pointer;
    }
};

// 防止编译器优化
A return_rvalue(bool test) {
    A a, b;
    if (test) return a; // 等价于 static_cast<A&&>(a);
    else return b;     // 等价于 static_cast<A&&>(b);
}

void func1() {
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;
}

void func2() {
    std::string str = "Hello world.";
    std::vector<std::string> v;

    // 将使用 push_back(const T&), 即产生拷贝行为
    v.push_back(str);
    // 将输出 "str: Hello world."
    std::cout << "str: " << str << std::endl;

    // 将使用 push_back(const T&&), 不会出现拷贝行为
    // 而整个字符串会被移动到 vector 中，所以有时候 std::move 会用来减少拷贝出现的开销
    // 这步操作后, str 中的值会变为空
    v.push_back(std::move(str));
    // 将输出 "str: "
    std::cout << "str: " << str << std::endl;
}

int main() {
    func2();
    return 0;
}