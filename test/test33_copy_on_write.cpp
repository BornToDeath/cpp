//
// Created by lixiaoqing on 2022/6/30.
//

#include <iostream>
#include <string>

void test01() {
    /**
     * STL 中的 std::string 类，也是一个具有写时拷贝技术的类。为了提高性能，STL 中的许多类都采用了写时拷贝技术，
     * 但是在 C++11 标准中为了提高并行性取消了这一策略。
     */
    std::string s1 = "Hello, world";
    std::string s2 = s1;
    printf("%c, %c\n", (s1[0]), (s2[0]));
    printf("%x, %x\n", &(s1[0]), &(s2[0]));

}

int main() {
    test01();
    return 0;
}