//
// Created by lixiaoqing on 2022/3/15.
//

#include <iostream>
#include <mutex>
#include "Application.h"

static std::shared_ptr<IApplication> singleton = nullptr;

extern "C" {
void Log(const char *text);
}

void Log(const char *text) {
#ifdef __cplusplus
    std::cout << "[C]Log|c++" << std::endl;
#else
    std::cout << "[C]Log|c" << std::endl;
#endif
    printf("%s\n", text);
}

void Log2(const char *text) {
    printf("%s\n", text);
}

void Log3(const std::string &text) {
    printf("%s\n", text.c_str());
}

std::shared_ptr<IApplication> IApplication::getSingleton() {
    static std::once_flag onceFlag;
    std::call_once(onceFlag, []() {
        auto temp = std::make_shared<Application>();
        singleton = temp;
    });
    return singleton;
}

void IApplication::releaseSingleton() {
    singleton = nullptr;
}

void Application::start() {

#ifdef __cplusplus
    std::cout << "Application|c++" << std::endl;
#else
    std::cout << "Application|c" << std::endl;
#endif

    Log("启动 Application");
    Log2("启动 Application 2");
    Log3("启动 Application 3");

    int SIZE = 256;
//    char arr[SIZE] = {};  // error, need: const int SIZE = 256;
}