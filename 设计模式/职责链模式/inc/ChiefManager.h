//
// Created by lixiaoqing on 2022/3/10.
//

#ifndef CHAINOFRESPONSIBILITY_CHIEFMANAGER_H
#define CHAINOFRESPONSIBILITY_CHIEFMANAGER_H

#include "Manager.h"

/**
 * 总监（经理主管）
 */
class ChiefManager : public Manager {

public:

    explicit ChiefManager(const std::string &name) : Manager(name) {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~ChiefManager() override {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:

    void requestApplications(std::shared_ptr<Request> request) override {
        if (request == nullptr) {
            return;
        }
        if (request->getType() == "请假" && request->getCount() <= 100) {
            std::cout << name << " 正在审批|"
                      << "类型:" << request->getType() << ", "
                      << "内容:" << request->getContent() << ", "
                      << "数量:" << request->getCount() << std::endl;
        } else if (superior != nullptr) {
            superior->requestApplications(request);
        }
    }

};

#endif //CHAINOFRESPONSIBILITY_CHIEFMANAGER_H
