//
// Created by lixiaoqing on 2022/8/10.
//

#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        /**
         * 方法1：借鉴桶思想
         * 时间复杂度 O(nlogn) ，空间复杂度 O(1)
         * https://leetcode.cn/problems/task-scheduler/solution/tong-zi-by-popopop/
         */
//        std::vector<int> taskCount(26, 0);
//        for (auto ch: tasks) {
//            ++taskCount[ch - 'A'];
//        }
//        // 对字母出现的次数进行降序排序
//        std::sort(taskCount.rbegin(), taskCount.rend());
//        int count = 0;
//        for (int i = 0; i < taskCount.size(); ++i) {
//            if (taskCount[i] != taskCount[0]) {
//                break;
//            }
//            ++count;
//        }
//        return std::max((int) tasks.size(), (taskCount[0] - 1) * (n + 1) + count);

        /**
         * 方法2：在方法1的基础上进行优化
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        std::vector<int> taskCount(26, 0);
        for (auto ch: tasks) {
            ++taskCount[ch - 'A'];
        }
        int count = 0, max = 0;
        for (int i : taskCount) {
            if (i > max) {
                max = i;
                count = 1;
            } else if (i == max) {
                ++count;
            }
        }
        return std::max(static_cast<int>(tasks.size()), (max - 1) * (n + 1) + count);
    }
};

int main() {
    std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    std::cout << Solution().leastInterval(tasks, 2) << std::endl;
    return 0;
}