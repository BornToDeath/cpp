//
// Created by lixiaoqing on 2022/10/12.
//

#include <iostream>

/**
 * 打印各类型的最大值
 * @tparam T
 * @tparam Tn
 */
template<typename T, typename ... Tn>
void for_each_max() {
    std::cout << typeid(T).name() << ": " << std::numeric_limits<T>::max() << std::endl;
    if constexpr(sizeof...(Tn) > 0) {
        for_each_max<Tn...>();
    }
}

int main() {
    for_each_max<int, float, double>();
    return 0;
}