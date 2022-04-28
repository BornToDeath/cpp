//
// Created by lixiaoqing on 2022/3/24.
//

#include <iostream>
#include <vector>

using namespace std;

void printArray(const std::vector<int> &arr) {
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int> &array) {
        /**
         * 方法1：空间复杂度 O(n)
         */
        if (array.empty()) {
            return {};
        }

        // 1. 计算连续子数组最大和
        vector<int> dp(array.size());
        for (int i = 0; i < array.size(); ++i) {
            if (i == 0) {
                dp[i] = array[i];
                continue;
            }
            if (dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + array[i];
            } else {
                dp[i] = array[i];
            }
        }

        // 2. 从最大和所在的位置向前遍历
        vector<int> res;
        auto maxNum = *std::max_element(dp.begin(), dp.end());
        // 由于要找到长度最长的最大子数组，所以要从后向前找到最大值的位置
        int maxIndex;
        for (maxIndex = dp.size() - 1; maxIndex >= 0; --maxIndex) {
            if (dp[maxIndex] == maxNum) {
                break;
            }
        }
        res.push_back(array[maxIndex]);
        for (auto i = maxIndex - 1; i >= 0; --i) {
            if (dp[i] < 0) {
                break;
            }
            res.push_back(array[i]);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
//    vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    vector<int> array = {1, 2, -3, 4, -1, 1, -3, 2};
    auto res = Solution().FindGreatestSumOfSubArray(array);
    printArray(res);
    return 0;
}