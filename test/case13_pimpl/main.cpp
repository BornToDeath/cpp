//
// Created by lixiaoqing on 2022/10/17.
//

#include <iostream>
#include "Book.h"

int main() {
    Book book;
    book.print();
    book.setCount(10);
    std::cout << book.getCount() << std::endl;
    return 0;
}