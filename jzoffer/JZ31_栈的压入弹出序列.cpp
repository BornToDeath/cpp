//
// Created by lixiaoqing on 2022/3/16.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int index = 0;
        for (const auto num: pushV) {
            _stack.push(num);
            while (!_stack.empty() && index < popV.size() && _stack.top() == popV[index]) {
                _stack.pop();
                ++index;
            }
        }
        return _stack.empty();
    }

private:
    std::stack<int> _stack;
};

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {4, 3, 5, 1, 2};

    Solution solution;
    std::cout << std::boolalpha;
    std::cout << solution.IsPopOrder(v1, v2) << std::endl;
    return 0;
}