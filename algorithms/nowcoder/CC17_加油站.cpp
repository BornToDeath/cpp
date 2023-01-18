//
// Created by lixiaoqing on 2022/6/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param gas int整型vector
     * @param cost int整型vector
     * @return int整型
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        /**
         * 方法1：时间复杂度O(n^2)
         */
//        const int SIZE = gas.size();
//        for (int i = 0; i < SIZE; ++i) {
//            int left = 0;
//            for (int j = i, k = 0; k < SIZE; ++k) {
//                left += gas[j] - cost[j];
//                if (left < 0) {
//                    break;
//                }
//                ++j;
//                j %= SIZE;
//                if (k == SIZE - 1) {
//                    return i;
//                }
//            }
//        }
//        return -1;

        /**
         * 方法2：在方法1的基础上进行优化，时间复杂度O(n)
         */
        int left = 0, total = 0, pos = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            left += gas[i] - cost[i];
            if (left < 0) {
                left = 0;
                pos = i + 1;
            }
        }
        return total >= 0 ? pos : -1;
    }
};

int main() {
    std::vector<int> gas = {2, 3, 1};
    std::vector<int> cost = {3, 1, 2};
    std::cout << Solution().canCompleteCircuit(gas, cost) << std::endl;
    return 0;
}