//
// Created by lixiaoqing on 2022/3/4.
//

#ifndef DECORATIONPATTERN_DECORATORTSHIRT_H
#define DECORATIONPATTERN_DECORATORTSHIRT_H

#include "Decorator.h"

class DecoratorTshirts : public Decorator {

public:

    DecoratorTshirts(std::shared_ptr<Person> person) : Decorator(person) {

    }

    void show() override {
        Decorator::show();
        std::cout << "  T恤" << std::endl;
    }

};

#endif //DECORATIONPATTERN_DECORATORTSHIRT_H
