//
// Created by lixiaoqing on 2022/10/17.
//

#include <iostream>
#include "Book.h"

class Book::Impl {
public:
    Impl() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Impl() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:
    void print() const {
        std::cout << "Hello world." << std::endl;
    }

    void setCount(int count) {
        this->count = count;
    }

    int getCount() const {
        return this->count;
    }

private:
    int count{10};
};

Book::Book() : pimpl(new Impl()) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Book::~Book() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
//    delete pimpl;
//    pimpl = nullptr;
    std::cout << "Book 析构结束" << std::endl;
}

void Book::print() const {
    return pimpl->print();
}

void Book::setCount(int count) const {
    pimpl->setCount(count);
}

int Book::getCount() const {
    return pimpl->getCount();
}

