//
// Created by lixiaoqing on 2022/3/10.
//

#ifndef CHAINOFRESPONSIBILITY_MANAGER_H
#define CHAINOFRESPONSIBILITY_MANAGER_H

#include <string>
#include <memory>
#include <iostream>
#include "Request.h"

/**
 * 管理者
 */
class Manager {

public:

    explicit Manager(const std::string &name) : name(name) {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    virtual ~Manager() {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };

public:

    void setSuperior(std::shared_ptr<Manager> superior) {
        this->superior = superior;
    }

    virtual void requestApplications(std::shared_ptr<Request> request) {
        std::cout << "这是 Manager 类 | "
                  << name << " 正在审批|"
                  << "类型:" << request->getType() << ", "
                  << "内容:" << request->getContent() << ", "
                  << "数量:" << request->getCount() << std::endl;
        if (superior && request) {
            superior->requestApplications(request);
        }
    };

protected:

    // 管理者姓名
    std::string name;

    // 管理者上级
    std::shared_ptr<Manager> superior;
};

#endif //CHAINOFRESPONSIBILITY_MANAGER_H
