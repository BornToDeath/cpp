//
// Created by lixiaoqing on 2022/10/17.
//

#ifndef PIMPL_BOOK_H
#define PIMPL_BOOK_H

class Book {

public:
    Book();

    ~Book();

    void print();

    void setCount(int count);

    int getCount() const;

public:
    class Impl;

    Impl *pimpl;
};


#endif //PIMPL_BOOK_H
