//
// Created by lixiaoqing on 2023/1/5.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        /**
         * 方法：借助双端队列。
         * 1. 队列负责记录窗口范围内的元素，并且降序排列；由于队列中记录的都是窗口内的元素，所以他们都是窗口内第一大、第二大...的树；
         * 2. 保证队列中只记录窗口范围内元素的数的方法是：右边进一个，左边出一个；
         * 3. 由于队列头部中的较大元素并不一定在窗口内，所以需要进行判断。
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        if (size <= 0 || size > num.size()) {
            return {};
        }

        std::vector<int> res;
        std::deque<int> d;
        for (int i = 0; i < num.size(); ++i) {
            // 如果比队列尾部元素大，则删除队列尾部元素，直至小于尾部元素，保证队列降序排列
            while (!d.empty() && num[i] >= num[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            // 删除队列头部不在窗口范围内的元素
            while (!d.empty() && i - d.front() + 1 > size) {
                d.pop_front();
            }
            // 记录窗口范围内的最大值
            if (i + 1 >= size) {
                res.push_back(num[d.front()]);
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> num = {2, 3, 4, 2, 6, 2, 5, 1};
    int size = 3;
    auto res = Solution().maxInWindows(num, size);
    for (auto e: res) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    return 0;
}

