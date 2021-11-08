//
// Created by lixiaoqing on 2021/11/4.
//

#include <iostream>
#include <string>

enum class Month : int {
    Jan = 0,
    Feb,
    Mar,
    Apr,
    May
};

void test01() {
    Month month;
    auto val = static_cast<std::underlying_type<Month>::type>(month);
    std::cout << val << std::endl;
    auto m2 = Month(val);
    std::to_string()
}

int main() {
    test01();
    return 0;
}

