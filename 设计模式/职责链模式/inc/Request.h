//
// Created by lixiaoqing on 2022/3/10.
//

#ifndef CHAINOFRESPONSIBILITY_REQUEST_H
#define CHAINOFRESPONSIBILITY_REQUEST_H

#include <string>

/**
 * 请求
 */
class Request final {

public:

    Request() = default;

public:

    std::string getType() const {
        return this->type;
    }

    void setType(const std::string &type) {
        this->type = type;
    }

    std::string getContent() const {
        return this->content;
    }

    void setContent(const std::string &content) {
        this->content = content;
    }

    int getCount() const {
        return this->count;
    }

    void setCount(int count) {
        this->count = count;
    }

private:

    // 申请类型
    std::string type;

    // 申请内容
    std::string content;

    // 申请数量
    int count = 0;

};

#endif //CHAINOFRESPONSIBILITY_REQUEST_H
