//
// Created by lixiaoqing on 2021/11/10.
//

/**
 * 结论：本例中，还是构造一次，频繁赋值的方法更省时
 *  test01 耗时：12031 us
 *  test02 耗时：27068 us
 */

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

unsigned long long getCurrentTimeMills();

void test01();

void test02();

void test03();
void test04();


int main() {
//    auto t1 = getCurrentTimeMills();
//    test01();
//    auto t2 = getCurrentTimeMills();
//    std::cout << "test01 耗时：" << (t2-t1) << std::endl;
//
//    t1 = getCurrentTimeMills();
//    test02();
//    t2 = getCurrentTimeMills();
//    std::cout << "test02 耗时：" << (t2-t1) << std::endl;

    test04();
    return 0;
}

void test01() {
    std::string str("");
    for (int i = 0; i < 100000; ++i) {
        str = "mei xiang ni yi ci, tian shang jiu piao luo yi li sha, yu shi bian you le sa ha la. mei xiang ni yi ci, tian shang jiu luo xia yi di shui, yu shi bian you le tai ping yang.";
        std::string aaa = str;
    }
}

void test02() {
    for (int i = 0; i < 100000; ++i) {
        std::string str(
                "mei xiang ni yi ci, tian shang jiu piao luo yi li sha, yu shi bian you le sa ha la. mei xiang ni yi ci, tian shang jiu luo xia yi di shui, yu shi bian you le tai ping yang.");
        std::string aaa = str;
    }
}

unsigned long long getCurrentTimeMills() {
    // 微秒
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()
    );
    return us.count();
}

void test03() {
    std::cout << std::boolalpha;
    std::string s1 = "100000";
    std::string s2 = "100001";
    std::cout << s1.compare(s2) << std::endl;
    std::cout << (s1 < s2) << std::endl;
}

void test04() {
    class A {
    public:
        std::string s;
    };

    A a;
    std::cout << sizeof(a) << std::endl;

    a.s.append("123");
    std::cout << sizeof(a) << std::endl;
}