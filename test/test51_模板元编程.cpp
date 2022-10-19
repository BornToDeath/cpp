//
// Created by lixiaoqing on 2022/10/12.
//

#include <iostream>

using namespace std;

/**
 * 打印各类型的最大值
 * @tparam T
 * @tparam Tn
 */
template<typename T, typename ... Tn>
void for_each_max() {
    std::cout << typeid(T).name() << ": " << std::numeric_limits<T>::max() << std::endl;
    if constexpr(sizeof...(Tn) > 0) {
        for_each_max<Tn...>();
    }
}

void test01() {
    for_each_max<int, float, double>();
}

// ----------------------------

class A {
public:
    void func1() {
        cout << "A" << endl;
    }
};

class B {
public:
    void func2() {
        cout << "B" << endl;
    }
};

// C++17 支持
template<typename T>
void func(T *t) {
    if constexpr(std::is_same<T, A>::value) {
        t->func1();
    } else if constexpr(std::is_same<T, B>::value) {
        t->func2();
    }
}

void test02() {
    auto a = new A();
    func(a);
    auto b = new B();
    func(b);
}

// ----------------------------

// C++11 支持
template<typename T, typename std::enable_if<std::is_same<T, A>::value, void *>::type = nullptr>
void run(T *t) {
    t->func1();
}

template<typename T, typename std::enable_if<std::is_same<T, B>::value, void *>::type = nullptr>
void run(T *t) {
    t->func2();
}

void test03() {
    auto a = new A();
    run(a);
    auto b = new B();
    run(b);
}

// ----------------------------

int main() {
    test03();
    return 0;
}