//
// Created by lixiaoqing on 2022/6/15.
//

#include <iostream>
#include <string_view>

std::string_view getView() {
    std::string str = "zhangsan";
    return std::string_view(str);
}

int main() {
    const char *cstr = "helloworld";
    std::string_view v1(cstr);
    std::string_view v2(cstr, 5);
    std::cout << v1 << ", " << v2 << std::endl;

    std::string str = "HELLOWORLD";
    std::string_view v3(str);  // string_view 内部定义了 string 到 string_view 的类型转换运算符
    std::string_view v4(str.c_str(), 5);
    std::cout << v3 << ", " << v4 << std::endl;

    auto v5 = getView();  // dangling pointer
    std::cout << v5 << std::endl;
    return 0;
}