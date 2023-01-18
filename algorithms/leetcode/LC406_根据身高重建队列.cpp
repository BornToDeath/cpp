//
// Created by lixiaoqing on 2022/8/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        /**
         * 方法：排序
         * 时间复杂度O(n^2)，空间复杂度O(logn)
         */
        // 1. 先进行排序：按身高降序、按 k 升序
        std::sort(people.begin(), people.end(), [](std::vector<int> &arr1, std::vector<int> &arr2) {
            if (arr1[0] > arr2[0] || arr1[0] == arr2[0] && arr1[1] < arr2[1]) {
                return true;
            }
            return false;
        });
        // 2. 再将元素插入到新数组 k 的位置
        std::vector<vector<int>> ans;
        for (auto &ele: people) {
            ans.insert(ans.begin() + ele[1], ele);
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> people = {{7, 0},
                                            {4, 4},
                                            {7, 1},
                                            {5, 0},
                                            {6, 1},
                                            {5, 2}};
    auto ans = Solution().reconstructQueue(people);
    for (auto &arr: ans) {
        for (auto num:arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}