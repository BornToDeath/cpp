//
// Created by lixiaoqing on 2022/8/19.
//

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
        /**
         * 方法1：遍历
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (startTime.empty() || endTime.empty()) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < startTime.size(); ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                ++count;
            }
        }
        return count;

    }
};