//
// Created by lixiaoqing on 2021/11/30.
//

#include <cstdarg>
#include "Log.h"

extern unsigned long long printTimestamp();

void myLog(const std::string logText, ...) {
    char log[1024]{};
    va_list args;
    va_start(args, logText);
    vsnprintf(log, sizeof(log), logText.c_str(), args);
    va_end(args);
    Log::debug(log);
}

void Log::debug(const std::string &logText) {
    std::cout << printTimestamp() << " | " << logText << std::endl;
}