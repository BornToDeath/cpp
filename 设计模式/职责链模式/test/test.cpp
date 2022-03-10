//
// Created by lixiaoqing on 2022/3/10.
//

#include "Employee.h"
#include "CommandManager.h"
#include "ChiefManager.h"
#include "GeneralManager.h"

int main() {
    auto generalManager = std::make_shared<GeneralManager>("CEO");

    auto chiefManager = std::make_shared<ChiefManager>("总监");
    chiefManager->setSuperior(generalManager);

    auto commandManager = std::make_shared<CommandManager>("经理");
    commandManager->setSuperior(chiefManager);

    auto employee = std::make_shared<Employee>("小明");
    employee->setSuperior(commandManager);

    auto request1 = std::make_shared<Request>();
    request1->setType("请假");
    request1->setContent("卑微小明想要请假");
    request1->setCount(5);
    employee->requestApplications(request1);

    request1->setType("请假");
    request1->setContent("卑微小明想要请假");
    request1->setCount(30);
    employee->requestApplications(request1);

    request1->setType("加薪");
    request1->setContent("卑微小明想要加薪");
    request1->setCount(10000);
    employee->requestApplications(request1);

    request1->setType("加薪");
    request1->setContent("卑微小明想要加薪");
    request1->setCount(1000000000);
    employee->requestApplications(request1);
}