//
// Created by lixiaoqing on 2022/6/8.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        /**
         * 方法1：时间复杂度O(n^2)
         */
//        std::vector<int> res;
//        for (int i = 0; i < n; ++i) {
//            int max = -1;
//            for (int j = i + 1; j < n; ++j) {
//                if (A[j] > A[i]) {
//                    max = A[j];
//                    break;
//                }
//            }
//            res.emplace_back(max);
//        }
//        return res;

        /**
         * 方法2：借助栈。时间复杂度O(n)
         */
        std::vector<int> res(n, -1);
        std::stack<int> _stack;
        for (int i = n - 1; i >= 0; --i) {
            while (!_stack.empty() && A[i] >= _stack.top()) {
                _stack.pop();
            }
            if (!_stack.empty()) {
                res[i] = _stack.top();
            }
            _stack.push(A[i]);
        }
        return res;
    }
};


int main() {
//    std::vector<int> arr = {11, 13, 10, 5, 12, 21, 3};
    std::vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto res = NextElement().findNext(arr, arr.size());
    for (auto num : res) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}