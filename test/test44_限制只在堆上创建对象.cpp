//
// Created by lixiaoqing on 2022/8/17.
//

#include <iostream>

/**
 * 限制只能在堆上创建对象：只将构造函数声明为私有的
 */
void test01() {
    class A {
    public:
        static A *create() {
            return new A();
        }

        ~A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }

    private:
        A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    auto a = A::create();
    delete a;
}

/**
 * 限制只能在堆上创建对象：只将析构函数声明为私有的
 */
void test02() {
    class A {
    public:
        void destroy() {
            delete this;
        }

        A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }

    private:
        ~A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    auto a = new A();
    a->destroy();
}

/**
 * 限制只能在堆上创建对象：同时将构造函数和析构函数都声明为私有的
 */
void test03() {
    class A {
    public:
        static A *create() {
            return new A();
        }

        void destroy() {
            delete this;
        }

    private:
        A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }

        ~A() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    auto a = A::create();
    a->destroy();
}

/**
 * 限制只能在栈上创建对象：重载 new 运算符并将其设为私有的
 */
void test04() {
    class A {
    private:
        void *operator new(size_t t) {}     // 注意函数的第一个参数和返回值都是固定的
        void operator delete(void *ptr) {}  // 重载了new就需要重载delete
    public:
        A() {}

        ~A() {}
    };
}

int main() {
    test03();
    return 0;
}