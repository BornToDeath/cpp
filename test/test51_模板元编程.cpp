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

/*
 * 利用模板实现编译期计算斐波那契数列。C++11 写法。下文提供了 C++17 写法。
 */

template<int N>
int fibonacci() {
    return fibonacci<N - 1>() + fibonacci<N - 2>();
}

template<>
int fibonacci<1>() {
    return 1;
}

template<>
int fibonacci<0>() {
    return 0;
}

void test04() {
    std::cout << fibonacci<10>() << std::endl;
    std::cout << fibonacci<20>() << std::endl;
}

// ----------------------------

/*
 * 利用模板实现编译期计算斐波那契数列。C++17 写法。
 */

template<int N>
constexpr int fibonacci2() {
    if constexpr(N <= 1) {
        return N;
    } else {  // else语句 必须有！
        return fibonacci2<N - 1>() + fibonacci2<N - 2>();
    }
}

void test05() {
    std::cout << fibonacci2<10>() << std::endl;
    std::cout << fibonacci2<20>() << std::endl;
}

// ----------------------------

/*
 * C++20 concept
 * 注意：如下代码可能编译不通过，因为 concept 特性在 Apple Clang 12.0.0 以上（包括）才被支持，且 12.0.0 只支持部分 concept 的特性！
 * https://en.cppreference.com/w/cpp/compiler_support
 */

//template<typename T>
//concept Integral = std::is_integral<T>::value;
//
//template<Integral T>
//bool equal(const T &a, const T &b) {
//    return a == b;
//}
//
//void test06() {
//    std::cout << equal(10, 20) << std::endl;
//    std::cout << equal(10, 10) << std::endl;
//    //std::cout << equal(10.11, 10.1) << std::endl;  // error
//}

// ----------------------------

class Person {
public:
    template<
            typename T,
            typename = typename std::enable_if<!std::is_same<Person, typename std::decay<T>::type>::value>::type
    >
    explicit Person(T &&n) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    template<typename A, typename B = float>
    void print() {
        std::cout << "Hello world." << std::endl;
    }
};

void test07() {
    int num = 10;
    std::cout << "--------------------" << std::endl;
    Person p1(num);
    std::cout << "--------------------" << std::endl;
    Person p2(p1);
    std::cout << "--------------------" << std::endl;
    Person p3("123");
    std::cout << "--------------------" << std::endl;
    p3.print<int>();
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type sfinae_test(T value) {
    std::cout << "T is int" << std::endl;
}

void test08() {
    int num1 = 10;
    sfinae_test(num1);

    float num2 = 11.1;
//    sfinae_test(num2);  // error!
}

// ----------------------------

// 引用折叠
void test09() {
    int num = 10;
    std::cout << typeid(num).name() << std::endl;
    std::cout << "----------------------" << std::endl;

    const int &n1 = num;
    std::cout << typeid(n1).name() << std::endl;
    std::cout << std::is_same<decltype(n1), int>::value << std::endl;
    std::cout << std::is_same<decltype(n1), int &>::value << std::endl;
    std::cout << std::is_same<decltype(n1), const int &>::value << std::endl;
    std::cout << "----------------------" << std::endl;

    auto n2 = n1;
    std::cout << typeid(n2).name() << std::endl;
    std::cout << std::is_same<decltype(n2), int>::value << std::endl;
    std::cout << std::is_same<decltype(n2), int &>::value << std::endl;
    std::cout << std::is_same<decltype(n2), const int &>::value << std::endl;
    std::cout << "----------------------" << std::endl;

    auto &&n3 = n1;
    std::cout << typeid(n3).name() << std::endl;
    std::cout << std::is_same<decltype(n3), int>::value << std::endl;
    std::cout << std::is_same<decltype(n3), int &>::value << std::endl;
    std::cout << std::is_same<decltype(n3), const int &>::value << std::endl;
    std::cout << "----------------------" << std::endl;

    auto &&n4 = 10;
    std::cout << typeid(n4).name() << std::endl;
    std::cout << std::is_same<decltype(n4), int>::value << std::endl;
    std::cout << std::is_same<decltype(n4), int &>::value << std::endl;
    std::cout << std::is_same<decltype(n4), const int &>::value << std::endl;
    std::cout << std::is_same<decltype(n4), int &&>::value << std::endl;
    std::cout << std::is_same<decltype(n4), const int &&>::value << std::endl;
    std::cout << "----------------------" << std::endl;

    decltype(auto) n5 = 10;
    std::cout << std::is_same<decltype(n4), int>::value << std::endl;
    std::cout << std::is_same<decltype(n4), int &>::value << std::endl;
    std::cout << std::is_same<decltype(n4), const int &>::value << std::endl;
    std::cout << std::is_same<decltype(n4), int &&>::value << std::endl;
    std::cout << std::is_same<decltype(n4), const int &&>::value << std::endl;
    std::cout << "----------------------" << std::endl;
}

// ----------------------------

int main() {
    test09();
    return 0;
}