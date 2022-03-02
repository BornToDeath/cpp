//
// Created by lixiaoqing on 2022/1/21.
//

#include <iostream>

void test01() {
#ifdef __cplusplus
    std::cout << "Defined" << std::endl;
    /**
     * 输出：
     *   199711(C++98)，如果CMakeLists中不指定则是这个
     *   201103(C++11)
     *   201402(C++14)
     */
    std::cout << __cplusplus << std::endl;
#else
    std::cout << "Not defined" << std::endl;
#endif
}

#define PRINT_LOG 0

#define printLog(format, ...)  {         \
    if (PRINT_LOG) {                     \
        printf(format, ##__VA_ARGS__);   \
        printf("\n");                    \
    }                                    \
}

int main() {
    test01();
    printLog("你好, %s", "李小庆");
    return 0;
}