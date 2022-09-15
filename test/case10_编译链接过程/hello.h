//
// Created by lixiaoqing on 2022/9/14.
//

#ifndef HELLO_H
#define HELLO_H

class A {
public:
    __attribute__((visibility ("default"))) void aaa();
    __attribute__((visibility ("hidden"))) void bbb();
    __attribute__((visibility ("hidden"))) void ccc();
};

#endif //HELLO_H
