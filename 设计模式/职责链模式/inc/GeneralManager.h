//
// Created by lixiaoqing on 2022/3/10.
//

#ifndef CHAINOFRESPONSIBILITY_GENERALMANAGER_H
#define CHAINOFRESPONSIBILITY_GENERALMANAGER_H

#include "Manager.h"

/**
 * 总经理
 */
class GeneralManager : public Manager {

public:

    explicit GeneralManager(const std::string &name) : Manager(name) {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~GeneralManager() override {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:

    void requestApplications(std::shared_ptr<Request> request) override {
        if (request == nullptr) {
            return;
        }
        auto type = request->getType();
        if (type == "请假") {
            std::cout << name << " 正在审批|"
                      << "类型:" << request->getType() << ", "
                      << "内容:" << request->getContent() << ", "
                      << "数量:" << request->getCount() << std::endl;
            return;
        }
        if (type == "加薪") {
            if (request->getCount() <= 100000) {
                std::cout << name << " 正在审批|"
                          << "类型:" << request->getType() << ", "
                          << "内容:" << request->getContent() << ", "
                          << "数量:" << request->getCount() << std::endl;
                return;
            }
            std::cout << "加薪不通过|"
                      << name << " 正在审批|"
                      << "类型:" << request->getType() << ", "
                      << "内容:" << request->getContent() << ", "
                      << "数量:" << request->getCount() << std::endl;
        }
//        Manager::requestApplications(request);
        if (superior) {
            superior->requestApplications(request);
        }
    }
};

#endif //CHAINOFRESPONSIBILITY_GENERALMANAGER_H
