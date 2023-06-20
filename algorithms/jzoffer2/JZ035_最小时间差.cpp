//
// Created by lixiaoqing on 2023/6/20.
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        /*
         * 方法: 排序
         * 时间复杂度 O(nlogn), 空间复杂度 O(logn) (快排的空间复杂度)
         */
        const int n = timePoints.size();
        if (n > 24 * 60) {  // 最多有 1440 种时间情况，如果超过，说明有重复的
            return 0;
        }
        int ans = INT_MAX;
        auto toMinutes = [](const std::string &time) {
            return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[3] - '0') * 10 + (time[4] - '0'));
        };
        std::sort(timePoints.begin(), timePoints.end());

        for (int i = 0; i < n; ++i) {
            auto m1 = toMinutes(timePoints[i % n]);
            auto m2 = toMinutes(timePoints[(i + 1) % n]);
            if (i == n - 1) {
                m2 += 24 * 60;
            }
            ans = std::min(ans, m2 - m1);

        }
        return ans;
    }
};

int main() {
    std::vector<std::string> points = {"23:59", "00:00"};
    points = {"00:00", "23:59", "00:00"};
    std::cout << Solution().findMinDifference(points) << std::endl;
}