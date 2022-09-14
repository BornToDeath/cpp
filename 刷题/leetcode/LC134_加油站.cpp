//
// Created by lixiaoqing on 2022/9/6.
//

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        /**
         * 方法1：逐一判断，不AC，时间超限
         * 时间复杂度 O(n^2) ，空间复杂度 O(1)
         */
//        for (int i = 0; i < gas.size(); ++i) {
//            if (complete(gas, cost, i)) {
//                return i;
//            }
//        }
//        return -1;

        /**
         * 方法2：只要总油量大于总耗油量就可以走完一圈
         * 参考：https://leetcode.cn/problems/gas-station/solution/by-nehzil-nnws/
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int total = 0, left = 0, pos = -1;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            left += gas[i] - cost[i];
            // 如果剩余油量 left 小于0，则更换起始站点
            if (left < 0) {
                left = 0;
                pos = i + 1;
            }
        }
        return total >= 0 ? pos : -1;
    }

private:
    bool complete(std::vector<int> &gas, std::vector<int> &cost, int pos) {
        int sum = 0, size = gas.size();
        for (int i = 0; i < size; ++i) {
            sum += gas[pos] - cost[pos];
            if (sum < 0) {
                return false;
            }
            pos = (pos + 1) % size;
        }
        return true;
    }
};

int main() {
    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};
//    std::vector<int> gas = {2, 3, 4};
//    std::vector<int> cost = {3, 4, 3};
    std::cout << Solution().canCompleteCircuit(gas, cost) << std::endl;
    return 0;
}