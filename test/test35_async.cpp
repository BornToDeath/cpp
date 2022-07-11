//
// Created by lixiaoqing on 2022/7/11.
//

#include <future>

void test01() {
    printf("[%llu]Enter test01\n", std::this_thread::get_id());
    auto func = []() {
        printf("[%llu]Enter func\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::seconds(1));
        printf("Leave func\n");
    };
    auto f = std::async(std::launch::deferred, func);
    printf("After async\n");
    f.get();  // 此处，std::async 中的 func 是同步的，并且在同一个线程中执行！
    printf("Leave test01\n");
}

int main() {
    test01();
    return 0;
}