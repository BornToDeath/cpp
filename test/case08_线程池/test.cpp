//
// Created by lixiaoqing on 2022/4/26.
//

#include <iostream>
#include "ThreadPool.h"

int main() {

    std::vector<std::future<int> > results;

    {
        ThreadPool pool(2);
        for (int i = 1; i <= 5; ++i) {
            results.emplace_back(
                    pool.enqueue([i] {
                        auto tid = std::this_thread::get_id();
                        printf("%llu | hello %d\n", tid, i);
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        printf("%llu | world %d\n", tid, i);
//                        if (i == 5) {
//                            while (true) {
//                                std::this_thread::sleep_for(std::chrono::seconds(10));
//                            }
//                        }
                        return i;
                    })
            );
        }

        std::this_thread::sleep_for(std::chrono::seconds(10));
        printf("leave\n");

        // 此时，在离开此作用域之前，线程池将要被析构，等待所有任务执行完毕后，线程一一释放。如果线程池中存在死循环的线程，则主线程阻塞于此。
    }
    printf("线程池已被释放\n");
    // 此时，线程池已经析构，线程池中的线程也已被释放。

    std::this_thread::sleep_for(std::chrono::seconds(10));
    for (auto &&result: results) {
        printf("i=%d\n", result.get());
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));
    printf("进程退出\n");
    return 0;
}