//
// Created by lixiaoqing on 2022/5/26.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>> &matrix) {
    for (const auto &arr: matrix) {
        for (auto num: arr) {
            std::cout << num << ",";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    int minmumNumberOfHost(int n, vector<vector<int> > &startEnd) {
        /**
         * 方法1：比较复杂
         */
//        if (startEnd.empty()) {
//            return 0;
//        }
//        std::sort(startEnd.begin(), startEnd.end());
////        print(startEnd);
//        std::vector<int> dp;
//        dp.push_back(startEnd[0][1]);
//        for (int i = 1; i < startEnd.size(); ++i) {
//            bool flag = false;
//            for (auto &ele: dp) {
//                if (ele <= startEnd[i][0]) {
//                    ele = startEnd[i][1];
//                    flag = true;
//                    break;
//                }
//            }
//            if (!flag) {
//                dp.push_back(startEnd[i][1]);
//            }
////            print(dp);
//        }
//        return dp.size();

        /**
         * 方法2（推荐）：时间复杂度 O(logn) ，空间复杂度 O(n)
         */
        std::vector<int> starts;
        std::vector<int> ends;
        for (const auto &ele:startEnd) {
            starts.push_back(ele[0]);
            ends.push_back(ele[1]);
        }
        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());
        int count = 0;
        for (int i = 0, j = 0; i < starts.size(); ++i) {
            // 如果某个活动的开始时间小于前一个活动的结束时间，则需要添加主持人
            if (starts[i] < ends[j]) {
                ++count;
            } else {
                ++j;
            }
        }
        return count;

        /**
         * 方法3：每次有活动开始时增加一个主持人，每次活动结束时减少一个主持人
         */
//        std::vector<int> starts;
//        std::vector<int> ends;
//        for (const auto &ele:startEnd) {
//            starts.push_back(ele[0]);
//            ends.push_back(ele[1]);
//        }
//        std::sort(starts.begin(), starts.end());
//        std::sort(ends.begin(), ends.end());
//        int max = 0;
//        int count = 0;
//        for (int i = 0, j = 0; i < starts.size(); ++i) {
//            ++count;
//            if (starts[i] >= ends[j]) {
//                --count;
//                ++j;
//            }
//            max = std::max(max, count);
//        }
//        return max;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {2147483646,  2147483647},
            {-2147483648, -2147483647},
            {2147483646,  2147483647},
            {-2147483648, -2147483647},
            {2147483646,  2147483647},
            {-2147483648, -2147483647},
            {2147483646,  2147483647},
            {-2147483648, -2147483647},
            {2147483646,  2147483647},
            {-2147483648, -2147483647}
    };
    std::cout << Solution().minmumNumberOfHost(matrix.size(), matrix) << std::endl;
    return 0;
}