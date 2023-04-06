//
// Created by lixiaoqing on 2023/4/6.
//

#include <iostream>

class A {
public:
    static void print() {
        printf("%s\n", __PRETTY_FUNCTION__);
    }

    static int count1;
    static int count2;
};

int A::count1 = 20;
int A::count2 = 30;

static int num = 10;

static void print() {
    printf("Hello world.\n");
//    A::count2 = 10;
    std::cout << A::count1 << std::endl;
    A::print();
}
