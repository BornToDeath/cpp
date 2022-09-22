//
// Created by lixiaoqing on 2022/9/22.
//

/**
 * 同花顺笔试题目
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool isValid(const std::string &str) {
    std::unordered_map<char, char> MAP = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
    };
    std::stack<char> _stack;
    for (auto ch: str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            _stack.push(MAP[ch]);
            continue;
        }
        if (_stack.empty() || ch != _stack.top()) {
            return false;
        }
        _stack.pop();
    }
    return _stack.empty();
}

int main() {
    std::string str = "{()[]}}";
//    std::string str = "{({)[}]}";
    std::cout << isValid(str) << std::endl;
    return 0;
}