//
// Created by lixiaoqing on 2022/6/20.
//

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res ^= num;
        }
        return res;
    }
};