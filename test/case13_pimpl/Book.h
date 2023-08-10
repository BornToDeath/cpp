//
// Created by lixiaoqing on 2022/10/17.
//

#ifndef PIMPL_BOOK_H
#define PIMPL_BOOK_H

class Book {

public:
    Book();

    ~Book();

public:

    void print() const;

    void setCount(int count) const;

    int getCount() const;

public:
    class Impl;

    std::unique_ptr<Impl> pimpl;
};


#endif //PIMPL_BOOK_H
