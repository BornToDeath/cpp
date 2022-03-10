//
// Created by lixiaoqing on 2022/3/10.
//

#ifndef CHAINOFRESPONSIBILITY_COMMANDMANAGER_H
#define CHAINOFRESPONSIBILITY_COMMANDMANAGER_H

#include "Manager.h"

/**
 * 经理
 */
class CommandManager : public Manager {

public:

    explicit CommandManager(const std::string &name) : Manager(name) {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~CommandManager() override {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:

    void requestApplications(std::shared_ptr<Request> request) override {
        if (request == nullptr) {
            return;
        }
        if (request->getType() == "请假" && request->getCount() <= 10) {
            std::cout << name << " 正在审批|"
                      << "类型:" << request->getType() << ", "
                      << "内容:" << request->getContent() << ", "
                      << "数量:" << request->getCount() << std::endl;
        } else if (superior != nullptr) {
            superior->requestApplications(request);
        }
    }

};

#endif //CHAINOFRESPONSIBILITY_COMMANDMANAGER_H
