//
// Created by lixiaoqing on 2022/3/4.
//

#ifndef DECORATIONPATTERN_DECORATORHAT_H
#define DECORATIONPATTERN_DECORATORHAT_H

#include "Decorator.h"

class DecoratorHat : public Decorator {

public:

    DecoratorHat(std::shared_ptr<Person> person) : Decorator(person) {

    };

    void show() override {
        Decorator::show();
        std::cout << "  帽子" << std::endl;
    }

};


#endif //DECORATIONPATTERN_DECORATORHAT_H
