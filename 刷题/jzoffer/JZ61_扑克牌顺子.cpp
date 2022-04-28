//
// Created by lixiaoqing on 2022/4/8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        std::bitset<16> bs;
        auto min = -1;
        auto max = -1;
        for (int i = 0; i < numbers.size(); ++i) {
            auto num = numbers[i];
            if (num == 0) {
                continue;
            }
            // 不允许有重复值
            if (bs[num]) {
                return false;
            }
            bs.set(num);
            if (max == -1) {
                min = max = num;
                continue;
            }
            if (num > max) {
                max = num;
            } else if (num < min) {
                min = num;
            }
        }
        // 最大值最小值（除0）之差不能超过4
        if (max - min > 4) {
            return false;
        }
        return true;
    }
};