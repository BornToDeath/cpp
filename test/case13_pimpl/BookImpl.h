//
// Created by lixiaoqing on 2022/10/17.
//

#ifndef PIMPL_IMPL_H
#define PIMPL_IMPL_H

#include <iostream>
#include "Book.h"

class Book::Impl {
public:
    void print() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    void setCount(int count) {
        this->count = count;
    }

    int getCount() const {
        return this->count;
    }

private:
    int count{0};
};

#endif //PIMPL_IMPL_H
