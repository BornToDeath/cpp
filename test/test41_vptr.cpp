//
// Created by lixiaoqing on 2022/7/24.
//

#include <iostream>

typedef void (*Func)();

/**
 * 普通单一继承
 */
void test01() {
    class A {
    public:
        virtual void func1() {}
    };

    class B : public A {
    public:
        virtual void func2() {}
    };

    A *a = new A();
    long a_ptr = *(long *) a;  // A的虚函数表地址
    long func1_addr = *(long *) a_ptr;  // 虚函数func1的函数地址
    printf("A vtable: %p\n", a_ptr);
    printf("A func1: %p\n", func1_addr);

    B *b = new B();
    long b_ptr = *(long *) b;  // B的虚函数表地址
    printf("B vtable: %p\n", b_ptr);
    printf("B func1: %p\n", *(long *) b_ptr);
    printf("B func2: %p\n", *((long *) b_ptr + 1));
}

/**
 * 多继承
 */
void test02() {
    class A {
    public:
        virtual void func1() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };
    class B {
    public:
        virtual void func2() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };
    class C : public A, public B {
    public:
        virtual void func3() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    A *a = new A();
    B *b = new B();
    C *c = new C();

    printf("sizeof(A): %d\n", sizeof(A));
    printf("sizeof(B): %d\n", sizeof(B));
    printf("sizeof(C): %d\n", sizeof(C));

    printf("A vtable: %p\n", *(long *) a);  // A 的虚函数表地址
    printf("A func1: %p\n", *(long *) *(long *) a);  // A::func1()

    printf("B vtable: %p\n", *(long *) b);  // B 的虚函数表地址
    printf("B func2: %p\n", *(long *) *(long *) b);  // B::func2()

    printf("C vtable 1: %p\n", *(long *) c);   // 第一个虚函数表地址，指向 A 的虚函数表
    printf("C vtable 1 func1: %p\n", *(long *) *(long *) c);  // 指向 A::func1()
    printf("C vtable 1 func3: %p\n", *((long *) *(long *) c + 1));  // 指向 A::func3()
    printf("C vtable 2: %p\n", *((long *) c + 1));  // 第二个虚函数表地址，指向 B 的虚函数表
    printf("C vtable 2 func2: %p\n", *(long *) *((long *) c + 1));  // 指向 B::func2()

    Func C_func1 = (Func) (*(long *) *(long *) c);
    C_func1();
    Func C_func2 = (Func) (*(long *) *((long *) c + 1));
    C_func2();
    Func C_func3 = (Func) (*((long *) *(long *) c + 1));
    C_func3();
}

/**
 * 虚继承
 */
void test03() {
    class A {
    public:
        virtual void funcA() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };
    class B : virtual public A {
    public:
        virtual void funcB() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };
    class C : virtual public A {
    public:
        virtual void funcC() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };
    class D : public B, public C {
    public:
        virtual void funcD() {
            printf("%s\n", __PRETTY_FUNCTION__);
        }
    };

    printf("sizeof(A): %d\n", sizeof(A));
    printf("sizeof(B): %d\n", sizeof(B));
    printf("sizeof(C): %d\n", sizeof(C));
    printf("sizeof(D): %d\n", sizeof(D));

    A *a = new A();
    B *b = new B();
    C *c = new C();
    D *d = new D();

    printf("A vtable: %p\n", *(long *) a);
    printf("A funcA: %p\n", *(long *) *(long *) a);

    printf("B vtable: %p\n", *(long *) b);
    printf("B funcA: %p\n", *(long *) *(long *) b);
    printf("B funcB: %p\n", *((long *) *(long *) b + 1));

    printf("C vtable: %p\n", *(long *) c);
    printf("C funcA: %p\n", *(long *) *(long *) c);
    printf("C funcC: %p\n", *((long *) *(long *) c + 1));

    printf("D vtable 1: %p\n", *(long *) d);
    printf("D vtable 1 funcA: %p\n", *(long *) *(long *) d);
    printf("D vtable 1 funcB: %p\n", *((long *) *(long *) d + 1));
    printf("D vtable 1 funcD: %p\n", *((long *) *(long *) d + 2));
//    printf("D vtable 2: %p\n", *((long *) d + 1));
//    printf("D vtable 2 funcA: %p\n", *(long *) *((long *) d + 1));

//    Func funcA = (Func) (*((long *) *(long *) d + 2));
//    Func funcA = (Func) (*(long *) *((long *) d + 2));
//    funcA();
}


int main() {
    test03();
    return 0;
}