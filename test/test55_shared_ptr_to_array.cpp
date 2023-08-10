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

    // 1. 自定义析构函数
    std::shared_ptr<A> p1(new A[5], [](A *p) { delete[]p; });

    // 2. 使用删除器 std::default_delete, 其重载了函数调用运算符"()"
    std::shared_ptr<A> p2(new A[5], std::default_delete<A[]>());

    return 0;
}