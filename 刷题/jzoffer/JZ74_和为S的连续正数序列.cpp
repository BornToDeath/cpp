//
// Created by lixiaoqing on 2022/4/27.
//

#include <iostream>
#include <vector>

using namespace std;

void print(const std::vector<int> &v) {
    for (auto num: v) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

void print(const std::vector<std::vector<int>> &res) {
    for (auto &v: res) {
        for (auto &num: v) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {

        /**
         * 方法1：递归
         */

//        if (sum == 0) {
//            return {};
//        }
//        std::vector<std::vector<int>> res;
//        for (int i = 1; i <= sum / 2; ++i) {
//            findSequence(sum, i);
//            if (!nums.empty()) {
//                res.emplace_back(nums);
//            }
//        }
//        return res;

        /**
         * 方法2：滑动窗口
         */
        // 计算区间 [i, j] 中连续自然数的和
        auto AllSum = [](int i, int j) -> int {
            return (i + j) * (j - i + 1) / 2;
        };
        std::vector<std::vector<int>> res;
        int i = 1;  // 左指针
        int j = 2;  // 右指针
        while (i < j) {
            auto ele = AllSum(i, j);
            if (ele == sum) {
                std::vector<int> v;
                for (auto k = i; k <= j; ++k) {
                    v.emplace_back(k);
                }
                res.emplace_back(v);
                ++i;
                ++j;
            } else if (ele < sum) {
                ++j;
            } else if (ele > sum) {
                ++i;
            }
        }
        return res;
    }

private:
    void findSequence(int sum, int pos) {
        if (sum < pos) {
            nums.clear();
            return;
        }
        nums.emplace_back(pos);
        if (sum == pos) {
            return;
        }
        findSequence(sum - pos, pos + 1);
    }

private:
    std::vector<int> nums;
};

int main() {
    auto res = Solution().FindContinuousSequence(9);
    print(res);
    return 0;
}