//
// Created by lixiaoqing on 2022/3/4.
//

#ifndef DECORATIONPATTERN_DECORATOR_H
#define DECORATIONPATTERN_DECORATOR_H

#include <memory>
#include "Person.h"

class Decorator : public Person {

public:

    explicit Decorator(std::shared_ptr<Person> person) : Person("NoOne"), person(person) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    void show() override {
        if (person) {
            person->show();
        }
    }

protected:

    std::shared_ptr<Person> person;
};


#endif //DECORATIONPATTERN_DECORATOR_H
