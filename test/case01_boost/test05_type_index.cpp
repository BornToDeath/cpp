
#include <iostream>
#include "boost/type_index.hpp"

void test01() {
    const int a = 10;
    auto &b = a;
    auto c = &a;

    std::cout << typeid(a).name() << std::endl;  // 可以用 c++filt 对输出进行解析
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;

    std::cout << "--------------------------" << std::endl;

    std::cout << boost::typeindex::type_id<decltype(a)>().pretty_name() << std::endl;
    std::cout << boost::typeindex::type_id<decltype(b)>().pretty_name() << std::endl;
    std::cout << boost::typeindex::type_id<decltype(c)>().pretty_name() << std::endl;

    std::cout << "--------------------------" << std::endl;

    std::cout << boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
    std::cout << boost::typeindex::type_id_with_cvr<decltype(b)>().pretty_name() << std::endl;
    std::cout << boost::typeindex::type_id_with_cvr<decltype(c)>().pretty_name() << std::endl;

    std::cout << "--------------------------" << std::endl;

    std::vector<int> nums;
    std::cout << typeid(nums).name() << std::endl;
    std::cout << boost::typeindex::type_id_with_cvr<decltype(nums)>().pretty_name() << std::endl;
}

int main() {
    test01();
    return 0;
}