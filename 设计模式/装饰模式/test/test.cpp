//
// Created by lixiaoqing on 2022/3/4.
//

#include <iostream>
#include "Decorator.h"
#include "DecoratorHat.h"
#include "DecoratorPants.h"
#include "DecoratorTShirt.h"

void test01() {
    auto person = std::make_shared<Person>("LXQ");
    person->show();
    std::cout << "------------------------" << std::endl;

    // 装饰1
    auto decorator1 = std::make_shared<DecoratorHat>(person);
    decorator1->show();
    std::cout << "------------------------" << std::endl;

    // 装饰2
    auto decorator2 = std::make_shared<DecoratorPants>(decorator1);
    decorator2->show();
    std::cout << "------------------------" << std::endl;

    // 装饰3
    auto decorator3 = std::make_shared<DecoratorTshirts>(decorator2);
    decorator3->show();
}

int main() {
    test01();
    return 0;
}