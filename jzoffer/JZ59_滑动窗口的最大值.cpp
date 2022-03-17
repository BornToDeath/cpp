//
// Created by lixiaoqing on 2022/3/17.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        /**
         * 方法1：暴力解法。遍历每个窗口找最大值
         */
//        if (size <= 0 || size > num.size()) {
//            return {};
//        }
//        std::vector<int> maxArray;
//        for (int i = 0; i < num.size() - size + 1; ++i) {
//            auto maxNum = num[i];
//            for (int j = i; j < i + size; ++j) {
//                if (num[j] > maxNum) {
//                    maxNum = num[j];
//                }
//            }
//            maxArray.push_back(maxNum);
//        }
//        return maxArray;

        /**
         * 方法2：借助双端队列
         */

        if (size <= 0 || size > num.size()) {
            return {};
        }
        vector<int> res;
        deque<int> _deque;
        for (int i = 0; i < num.size(); i++) {
            // 当前值比队列尾部的大，删除队列尾部的元素，再将当前元素添加到队列中
            while (!_deque.empty() && num[i] > num[_deque.back()]) {
                _deque.pop_back();
            }
            _deque.push_back(i);

            // 当前队列头部已不再窗口中
            while (!_deque.empty() && i - _deque.front() + 1 > size) {
                _deque.pop_front();
            }

            // 当 i 大于 size 时才开始记录窗口最大值
            if (i + 1 >= size) {
                res.push_back(num[_deque.front()]);
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 4, 2, 6, 2, 5, 1};
    Solution solution;
    auto arr = solution.maxInWindows(nums, 3);
    for (const auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}