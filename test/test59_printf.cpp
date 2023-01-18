//
// Created by lixiaoqing on 2023/1/18.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>

class A {
public:
    A(int n) : n(n) {
        m2.lock();
    }

    void a() {
        for (int i = 0; i < n; ++i) {
            m1.lock();
            printf("a");
            m2.unlock();
        }
    }

    void b() {
        for (int i = 0; i < n; ++i) {
            m2.lock();
            printf("b");
            m1.unlock();
        }
    }

private:
    int n;
    std::condition_variable cv;
    std::mutex m1, m2;
};


int main() {
    setbuf(stdout, nullptr);  // 关闭缓冲区，使得 printf 可以立即输出，因为 printf 默认情况下输出是缓冲的，如果没有换行符，不会立即输出到标准输出
    auto p = new A(10);
    std::thread t1([p]() { p->a(); });
    std::thread t2([p]() { p->b(); });
    t1.join();
    t2.join();
    sleep(3);
    delete p;
    return 0;
}