//
// Created by lixiaoqing on 2022/10/13.
//

#include <iostream>
#include <time.h>

int main() {
    struct tm tm_t;
    tm_t.tm_year = 2022 - 1900;
    tm_t.tm_mon = 9 - 1;
    tm_t.tm_mday = 15;
    tm_t.tm_hour = 15;
    tm_t.tm_min = 20;
    tm_t.tm_sec = 36;
    tm_t.tm_isdst = 0;// 为在移动平台同样运行正确，必须设置为0或-1

    setenv("TZ", "Universal", 1);
    std::cout << mktime(&tm_t) << std::endl;

    setenv("TZ", "Asia/Shanghai", 1);
    std::cout << mktime(&tm_t) << std::endl;

    setenv("TZ", "CST-8", 1);
    std::cout << mktime(&tm_t) << std::endl;

    return 0;
}