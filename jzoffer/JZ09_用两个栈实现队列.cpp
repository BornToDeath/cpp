//
// Created by lixiaoqing on 2021/11/3.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                auto num = stack1.top();
                stack1.pop();
                stack2.push(num);
            }
        }
        auto ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution solution;
    solution.push(1);
    solution.push(2);
    std::cout << solution.pop() << std::endl;
    solution.push(3);
    std::cout << solution.pop() << std::endl;
    std::cout << solution.pop() << std::endl;
    return 0;
}