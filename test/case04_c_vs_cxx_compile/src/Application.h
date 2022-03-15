//
// Created by lixiaoqing on 2022/3/15.
//

#ifndef TEST_APPLICATION_H
#define TEST_APPLICATION_H

#include "IApplication.h"

class Application : public IApplication{

public:

    Application() = default;

    ~Application() override = default;

    void start() override;
};


#endif //TEST_APPLICATION_H
