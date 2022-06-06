//
// Created by lixiaoqing on 2022/6/6.
//

#include "gtest/gtest.h"

//namespace Test {
//    void test01() {
//        auto add = [](int a, int b) {
//            return a + b;
//        };
//    }
//}
//
//int add(int a, int b) {
//    return a + b;
//};
//
//TEST(Test, test01) {
//    EXPECT_EQ(add(4, 3), 7);
//}

int main() {
//    int num = 1;
//    printf(">>> %d\n", (num++) + (num++));  // 3
//    printf("num=%d\n", num);                // 3
//    printf(">>> %d\n", (++num) + (++num));  // 9
//    printf("num=%d\n", num);                // 5
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}