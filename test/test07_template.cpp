//
// Created by lixiaoqing on 2021/11/9.
//

#include <iostream>


namespace FunctionTemplateTest {

}

namespace ClassTemplateTest {

    /**
     * 普通模板
     * @tparam T
     */
    template<typename T>
    class Compare {
    public:
        bool isEqual(const T &, const T &);
    };

    template<typename T>
    bool Compare<T>::isEqual(const T &arg1, const T &arg2) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return (arg1 == arg2);  // float型和double型不能如此比较
    }

    /**
     * 模板全特化。
     * 全特化为 float 型模板
     */
    template<>
    class Compare<float> {
    public:
        bool isEqual(const float &arg1, const float &arg2);
    };

    bool Compare<float>::isEqual(const float &arg1, const float &arg2) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return (std::abs(arg1 - arg2) < 10e-3);
    }

    /**
     * 模板全特化。
     * 全特化为 double 型模板
     */
    template<>
    class Compare<double> {
    public:
        bool isEqual(const double &arg1, const double &arg2);
    };

    bool Compare<double>::isEqual(const double &arg1, const double &arg2) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return (std::abs(arg1 - arg2) < 10e-6);
    }

    void test01() {
        std::cout << std::boolalpha;

        Compare<int> com1;
        std::cout << com1.isEqual(10, 11) << std::endl;

        Compare<float> com2;
        std::cout << com2.isEqual(10.222, 10.2223) << std::endl;

        Compare<double> com3;
        std::cout << com3.isEqual(0.00000001, 0.0000002) << std::endl;
    }
}

int main() {
    ClassTemplateTest::test01();
    return 0;
}