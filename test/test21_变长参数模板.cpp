//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>

/**
 * 计算平均值
 * @tparam T
 * @param t
 * @return
 */
template<typename ... T>
auto avg(T ... t) {
    return (t + ...) / sizeof...(t);
}



int main() {
    std::cout << std::boolalpha;
    auto res = avg(1, 2, 3, 4, 5, 6.0, 7);
    std::cout << typeid(res).name() << std::endl;
    std::cout << std::is_same<decltype(res), int>::value << std::endl;
    std::cout << std::is_same<decltype(res), double>::value << std::endl;
    std::cout << res << std::endl;
    return 0;
}