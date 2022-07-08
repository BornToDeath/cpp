//
// Created by lixiaoqing on 2022/7/8.
//

#include <vector>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {
        int even = 0, odd = 0;
        for (int i = 1; i <= position.size(); ++i) {
            position[i - 1] % 2 ? ++odd : ++even;
        }
        return std::min(even, odd);
    }
};