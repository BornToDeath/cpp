//
// Created by lixiaoqing on 2021/11/30.
//

#include <chrono>
#include "Test.h"

extern void myLog(const std::string logText, ...);

extern "C" {
unsigned long long printTimestamp() {
    auto count = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
    return count;
}
}

void Test::printLog(const std::string &log) {
    myLog(log);
}