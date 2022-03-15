//
// Created by lixiaoqing on 2022/3/15.
//

#ifndef TEST_IAPPLICATION_H
#define TEST_IAPPLICATION_H

#include <memory>

class IApplication {

public:

    virtual ~IApplication() {};

    static std::shared_ptr<IApplication> getSingleton();

    static void releaseSingleton();

    virtual void start() = 0;

};

#endif //TEST_IAPPLICATION_H
