//
// Created by lixiaoqing on 2021/11/29.
//

#include <iostream>
#include <functional>

using Logger = std::function<void(int)>;

class A {
public:
    static void setLogger(Logger logger) {
        A::logger = logger;
    }

public:
    static Logger logger;
};

int main() {
    auto myLogger = [](int num) {

    };
    A::setLogger(myLogger);
    std::distance()

    std::fill()
    return 0;
}

template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last);