//
// Created by lixiaoqing on 2022/7/20.
//



/**
 * 方法1：使用 std::mutex + wait()
 */

#include <functional>
#include <mutex>
using namespace std;

class Foo {
public:
    Foo() {

    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        num = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {

        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this]() { return num == 1; });
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        num = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {

        {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [this]() { return num == 2; });
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    std::mutex mutex;
    std::condition_variable cv;
    int num{0};
};


/**
 * 方法2：使用信号量 sem_t
 * 参考：https://leetcode.cn/problems/print-in-order/solution/an-xu-da-yin-by-leetcode/
 */
