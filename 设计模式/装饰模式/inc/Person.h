//
// Created by lixiaoqing on 2022/3/4.
//

#ifndef DECORATIONPATTERN_PERSON_H
#define DECORATIONPATTERN_PERSON_H

#include <string>

class Person {

public:

    explicit Person(const std::string &name) : name(name) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    virtual void show() {
        std::cout << name << "装扮了:" << std::endl;
    }

private:

    std::string name;

};


#endif //DECORATIONPATTERN_PERSON_H
