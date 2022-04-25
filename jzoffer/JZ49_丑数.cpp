//
// Created by lixiaoqing on 2022/4/20.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <set>


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        /**
         * 方法1：利用 std::bitset, 但是这种方法不可行，原因是要先申请一块超大内存初始化 bitset
         */
//        return func1(index);

        /**
         * 方法2：暴力搜索。时间复杂度过高，不AC。时间复杂度O(Un)，其中Un是第n个丑数所对应的自然数
         */
//        return func2(index);

        /**
         * 方法3：借助 std::set, AC, 时间复杂度 O(3nlogn)
         */
//        return func3(index);

        /**
         * 方法4：三指针，AC，时间复杂度 O(n) 。记住吧
         */
        return func4(index);
    }

private:

    int func4(int index) {
        if (index == 0) {
            return 0;
        }
        std::vector<int> dp;
        dp.emplace_back(1);
        int i = 0, j = 0, k = 0;
        int num;
        while (dp.size() < index) {
            num = std::min(dp[i] * 2, std::min(dp[j] * 3, dp[k] * 5));
            dp.emplace_back(num);
            if (num == dp[i] * 2) {
                ++i;
            }
            if (num == dp[j] * 3) {
                ++j;
            }
            if (num == dp[k] * 5) {
                ++k;
            }
        }
        return dp[dp.size() - 1];
    }

    int func3(int index) {
        if (index <= 1) {
            return index;
        }
        std::set<long> _set;
        _set.insert(1);
        int count = 1;
        while (count < index) {
            auto ele = *_set.begin();
            _set.insert(ele * 2);
            _set.insert(ele * 3);
            _set.insert(ele * 5);
            _set.erase(_set.begin());
            ++count;
        }
        return *_set.begin();
    }

    int func2(int index) {
        // 判断一个数是否是丑数
        auto isUglyNumber = [](int number) -> bool {
            while (number % 2 == 0) {
                number /= 2;
            }
            while (number % 3 == 0) {
                number /= 3;
            }
            while (number % 5 == 0) {
                number /= 5;
            }
            return number == 1;
        };
        int count = 1;
        int num = 1;
        while (count < index) {
            ++num;
            if (isUglyNumber(num)) {
                ++count;
            }
        }
        return num;
    }

    int func1(int index) {

        auto dp = new std::bitset<INT32_MAX>();
        dp->set(1);
        int num = 1;
        const std::vector<int> NUMS = {2, 3, 5};
        while (dp->count() < index) {
            ++num;
            int ele = -1;
            for (int e: NUMS) {
                if (num % e == 0) {
                    ele = e;
                    break;
                }
            }
            if (ele == -1) {
                continue;
            }
            if (dp->test(num / ele)) {
                std::cout << num << ", ";
                dp->set(num);
            }
        }
        auto ele = num;
        for (; ele >= 0; --ele) {
            if (dp->test(ele)) {
                break;
            }
        }
        delete dp;
        return ele;
    }
};

int main() {
    std::cout << Solution().GetUglyNumber_Solution(10) << std::endl;
    return 0;
}