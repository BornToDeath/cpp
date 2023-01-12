//
// Created by lixiaoqing on 2023/1/12.
//

#include <memory>s

class A {
public:
    explicit A(int num) : num(num) {
        printf("%s|num=%d\n", __PRETTY_FUNCTION__, num);
    }

    ~A() {
        printf("%s|num=%d\n", __PRETTY_FUNCTION__, num);
//        throw;  // abort
    }

    int num;
};

void func1() {
    auto a = std::make_shared<A>(1);
    auto a2 = new A(4);  // wrong, won't release
    throw "exception";
}

void func2() {
    A a(2);
    func1();
    printf("in func2, after func1\n");
    A a2(3);
}

int main() {
    try {
        func2();
    } catch (const char *msg) {
        printf("catch: %s\n", msg);
    }
    return 0;
}