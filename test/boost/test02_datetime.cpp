//
// Created by lixiaoqing on 2021/11/16.
//

#include <iostream>
#include <string>
#include <locale>
#include "boost/date_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/signals2.hpp"


void test01() {
    std::string s("2001-10-9");
    boost::gregorian::date d1(boost::gregorian::from_simple_string(s));
}

void test02() {
    std::locale loc;
    std::cout << loc.name() << std::endl;
}

int main() {
    test02();
    return 0;
}