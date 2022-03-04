//
// Created by lixiaoqing on 2022/3/4.
//

#ifndef DECORATIONPATTERN_DECORATORPANTS_H
#define DECORATIONPATTERN_DECORATORPANTS_H

#include "Decorator.h"

class DecoratorPants : public Decorator {

public:

    DecoratorPants(std::shared_ptr<Person> person) : Decorator(person) {

    }

    void show() override {
        Decorator::show();
        std::cout << "  裤子" << std::endl;
    }

};

#endif //DECORATIONPATTERN_DECORATORPANTS_H
