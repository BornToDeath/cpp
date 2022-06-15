//
// Created by lixiaoqing on 2022/6/15.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> umap = {
                {'(', ')'},
                {'[', ']'},
                {'{', '}'}
        };
        std::stack<char> _stack;
        for (auto ch: s) {
            if (umap.find(ch) != umap.end()) {
                _stack.push(umap.at(ch));
            } else {
                if (_stack.empty() || ch != _stack.top()) {
                    return false;
                }
                _stack.pop();
            }
        }
        return _stack.empty();
    }
};

int main() {
    std::string str = "[](){}(}";
    std::cout << std::boolalpha << Solution().isValid(str) << std::endl;
    return 0;
}