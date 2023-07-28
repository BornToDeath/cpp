//
// Created by lixiaoqing on 2023/4/6.
//

#include <iostream>

static int b_global_static_num = 10;
int b_global_nonstatic_num = 20;
extern const int a_global_const_num;

void b_print() {
    printf("%s\n", __PRETTY_FUNCTION__);
    printf("%d\n", a_global_const_num);
}