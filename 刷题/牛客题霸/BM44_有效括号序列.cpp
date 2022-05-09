//
// Created by lixiaoqing on 2022/5/9.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        std::stack<char> _stack;
        for (auto ch: s) {
            if (ch == '(') {
                _stack.push(')');
            } else if (ch == '[') {
                _stack.push(']');
            } else if (ch == '{') {
                _stack.push('}');
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (_stack.empty() || _stack.top() != ch) {
                    return false;
                }
                _stack.pop();
            }
        }
        return _stack.empty();
    }
};

int main() {
    std::string str = "()[]{}";
    std::cout << Solution().isValid(str) << std::endl;
    return 0;
}