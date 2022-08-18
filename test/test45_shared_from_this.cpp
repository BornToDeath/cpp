//
// Created by lixiaoqing on 2022/8/18.
//

#include <memory>

void test01() {
    class A {
    public:
        A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }

        ~A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    auto a = new A();
    std::shared_ptr<A> p1(a);
    std::shared_ptr<A> p2(a);  // 有问题
    printf("%p\n", p1.get());
    printf("%p\n", p2.get());
}

void test02() {
    class A : public std::enable_shared_from_this<A> {
    public:
        A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }

        ~A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    auto a = new A();
//    auto p = a->shared_from_this();  // 有问题
    std::shared_ptr<A> p1(a);
    auto p2 = a->shared_from_this();  // 没问题
}

int main() {
    test02();
    return 0;
}