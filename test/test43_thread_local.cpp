//
// Created by lixiaoqing on 2022/8/9.
//

#include <iostream>
#include <thread>

class A {
public:
    A() {
        printf("%llu|%s\n", std::this_thread::get_id(), __PRETTY_FUNCTION__);
    }

    ~A() {
        printf("%llu|%s\n", std::this_thread::get_id(), __PRETTY_FUNCTION__);
    }

    void inc() {
        ++num;
    }

    int get() {
        return num;
    }

private:
    thread_local static int num;
};

thread_local int A::num = 10;

A a;

void test01() {
    printf("%llu|num=%d\n", std::this_thread::get_id(), a.get());
    a.inc();
    printf("%llu|num=%d\n", std::this_thread::get_id(), a.get());
}

int main() {
    test01();
    std::thread t1(test01);
    std::thread t2(test01);
    t1.join();
    t2.join();
    return 0;
}