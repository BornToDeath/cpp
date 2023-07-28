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

int a_global_nonstatic_num;
static int a_global_static_num;
static const int a_global_static_const_num = 10;
extern const int a_global_const_num = 10;
extern int a_global_extern_num;

static void print() {
    printf("Hello world.\n");
//    A::count2 = 10;
    std::cout << A::count1 << std::endl;
    A::print();
    static int a_local_static_num = 10;
}
