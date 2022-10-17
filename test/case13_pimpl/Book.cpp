//
// Created by lixiaoqing on 2022/10/17.
//

#include <iostream>
#include "Book.h"
#include "BookImpl.h"

Book::Book() : pimpl(new Impl()) {

}

Book::~Book() {
    delete pimpl;
    pimpl = nullptr;
}

void Book::print() {
    return pimpl->print();
}

void Book::setCount(int count) {
    pimpl->setCount(count);
}

int Book::getCount() const {
    return pimpl->getCount();
}

