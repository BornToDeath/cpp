//
// Created by lixiaoqing on 2023/1/10.
//

#include <iostream>
#include <memory>

class A {
public:
    A() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

    ~A() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }
};

__attribute__((constructor)) void before_main() {
    printf("-----before main-----\n");
}

__attribute__((destructor)) void after_main() {
    printf("-----after main-----\n");
}

int main() {
//    std::shared_ptr<A> p(new A[5]);  // wrong
    std::shared_ptr<A> p(new A[5], [](A *p) { delete[]p; });
    return 0;
}