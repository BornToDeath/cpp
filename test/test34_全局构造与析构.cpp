//
// Created by lixiaoqing on 2022/7/6.
//

/**
 * 结论：
 * 全局变量（包括 static 全局变量和非 static 全局变量）的构造发生 *main* 方法之前，按照声明的顺序进行构造；
 * 析构发生 *main* 方法之后，析构调用的顺序与构造的顺序相反。
 */

#include <iostream>

class A {
public:
    A(int num) : num(num) {
        printf("%s|num=%d\n", __PRETTY_FUNCTION__, num);
    }

    ~A() {
        printf("%s|num=%d\n", __PRETTY_FUNCTION__, num);
    }

private:
    int num;
};

static A a1(10);
A a2(20);

int main() {
    printf("main start\n");
    {
        A a3(30);
    }
    printf("main end\n");
    return 0;
}