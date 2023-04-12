//
// Created by lixiaoqing on 2023/4/12.
//

#ifndef TEST_STRING_H
#define TEST_STRING_H

/*
 * 基于 C++11 实现一个简单的 string
 * 参考: https://github.com/chenshuo/recipes/blob/master/string/StringTrivial.h
 */

#include <cstring>
#include <cassert>

class String final {

public:
    String() noexcept = default;

    String(const char *str, size_t len) : data_(len > 0 ? new char[len + 1] : nullptr), len_(len) {
        if (len > 0) {
            memcpy(data_, str, len_);
            data_[len] = '\0';
        } else {
            assert(data_ == nullptr);
        }
    }

    // 委托构造
    explicit String(const char *str) : String(str, strlen(str)) {

    }

    // 拷贝构造
    String(const String &rhs) : String(rhs.data_, rhs.len_) {

    }

    // 移动构造
    String(String &&rhs) noexcept: data_(rhs.data_), len_(rhs.len_) {
        rhs.data_ = nullptr;
        rhs.len_ = 0;
    }

    // 赋值构造
    String &operator=(String rhs) {
        // 此处形参传值不传引用，会发生一次拷贝，rhs 是临时对象，然后再将 rhs 与 this 进行交换，函数结束会对 rhs 进行析构
        swap(rhs);
        return *this;
    }

    ~String() {
        delete[] data_;
        data_ = nullptr;
        len_ = 0;
    }

    const char *c_str() const noexcept {
        return data_;
    }

    size_t size() const noexcept {
        return len_;
    }

private:
    void swap(String &rhs) noexcept {
        std::swap(data_, rhs.data_);
        std::swap(len_, rhs.len_);
    }

private:
    char *data_{nullptr};
    size_t len_{0};
};

#endif //TEST_STRING_H
