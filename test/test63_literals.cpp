//
// Created by boss on 2023/11/2.
//

#include <iostream>
#include <memory>
#include <thread>

// chrono literals
void test01() {
    // need c++14
    using namespace std::literals::chrono_literals;

    auto t1 = std::chrono::steady_clock::now();

    // s
    std::this_thread::sleep_for(1s);
    auto t2 = std::chrono::steady_clock::now();
    std::cout << "cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms"
              << std::endl;

    // ms
    std::this_thread::sleep_for(500ms);
    auto t3 = std::chrono::steady_clock::now();
    std::cout << "cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2).count() << "ms"
              << std::endl;
    std::cout << "cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(
            (t3.time_since_epoch() - t2.time_since_epoch())).count() << "ms" << std::endl;

    // h
    auto h = 2h - 1h;
    std::cout << h.count() << "h" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(h).count() << "s" << std::endl;
}

int main() {
    test01();
    return 0;
}