//
// Created by lixiaoqing on 2023/3/16.
//

#include <vector>
#include <stack>
#include <iostream>

using std::vector;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        /**
         * 时间复杂度 O(n + m) ，空间复杂度 O(n)
         */
        std::stack<int> _stack;
        int pos = 0;
        for (auto n: pushed) {
            _stack.push(n);
            while (!_stack.empty() && pos < popped.size() && _stack.top() == popped[pos]) {
                _stack.pop();
                ++pos;
            }
        }
        return _stack.empty() && pos >= popped.size();
    }
};

int main() {
    std::vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1, 0};
    std::cout << Solution().validateStackSequences(pushed, popped) << std::endl;
    return 0;
}