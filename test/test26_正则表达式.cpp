//
// Created by lixiaoqing on 2022/5/7.
//

#include <iostream>
#include <regex>

namespace Test {
    void test01() {
        // .* 展开是: ......... 无数个点，所以可以匹配任意多个任意字符
        std::regex regex(".*");
        const std::string str = "abcd";
        std::cout << std::boolalpha;
        std::cout << std::regex_match(str, regex) << std::endl;
    }
}

int main() {
    Test::test01();
    return 0;
}