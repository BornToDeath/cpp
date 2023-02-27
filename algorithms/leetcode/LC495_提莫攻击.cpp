//
// Created by lixiaoqing on 2023/2/27.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        /**
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (timeSeries.empty()) {
            return 0;
        }
        int sum = duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i - 1] + duration - 1 < timeSeries[i]) {
                sum += duration;
            } else {
                sum += timeSeries[i] - timeSeries[i - 1];
            }
        }
        return sum;
    }
};