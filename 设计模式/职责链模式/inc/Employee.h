//
// Created by lixiaoqing on 2022/3/10.
//

#ifndef CHAINOFRESPONSIBILITY_EMPLOYEE_H
#define CHAINOFRESPONSIBILITY_EMPLOYEE_H

#include "Manager.h"

/**
 * 员工
 */
class Employee : public Manager {

public :

    explicit Employee(const std::string &name) : Manager(name) {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Employee() override {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

public:

    void requestApplications(std::shared_ptr<Request> request) override {
        if (request && superior) {
            superior->requestApplications(request);
        } else {
            std::cout << "Employee|请求失败" << std::endl;
        }
    }

};

#endif //CHAINOFRESPONSIBILITY_EMPLOYEE_H
