//
// Created by lixiaoqing on 2021/11/4.
//

#include <iostream>
#include <memory>
using namespace std;

/**
运行结果：
>>> test01 start.
Person::Person()
A::A()
B::B()
>>> After construct p1,p2.
>>> After make shared.
Person::~Person()
B::~B()
A::~A()
>>> test01 end.

结论：
变量构造的顺序是：Person --- A --- B ，成员变量 A 和 B 构造时按照声明的顺序构造。
变量析构的顺序是：Person --- B --- A ，成员变量 A 和 B 析构时析构的顺序与声明的顺序相反。
 */


class A {
public:
    A() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~A() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class B {
public:
    B() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~B() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class Person {
public:
    Person() {
        cout << __PRETTY_FUNCTION__ << endl;
        p1 = make_shared<A>();
        p2 = make_shared<B>();
        cout << ">>> After construct p1,p2." << endl;
    }

    ~Person() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

private:
    shared_ptr<A> p1;
    shared_ptr<B> p2;
};

void test01() {
    cout << ">>> test01 start." << endl;
    {
        auto p = make_shared<Person>();
        cout << ">>> After make shared." << endl;
    }
    cout << ">>> test01 end." << endl;
}

void test02() {
    auto a = new A();
    std::shared_ptr<A> b(a);

    auto str = new std::string("123");
    std::shared_ptr<std::string> str1(str);
}

void test03() {
    auto a = std::make_shared<A>();
    std::cout << a.use_count() << std::endl;
    auto b = std::make_shared<A>();
    std::cout << a.use_count() << std::endl;
    std::cout << b.use_count() << std::endl;
}

int main() {
    test03();
    return 0;
}