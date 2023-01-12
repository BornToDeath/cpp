//
// Created by lixiaoqing on 2023/1/12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /**
         * 方法1：两个数组递推
         * 时间复杂度 O(rowIndex ^ 2) ，空间复杂度 O(rowIndex)
         */
//        if (rowIndex < 0) {
//            return {};
//        }
//        std::vector<int> ans(rowIndex + 1, 1);
//        for (int i = 1; i < rowIndex; ++i) {
//            auto temp = ans;
//            for (int j = 0; j < i; ++j) {
//                temp[j + 1] = ans[j] + ans[j + 1];
//            }
//            ans = temp;
//        }
//        return ans;

        /**
         * 方法2：一个数组，从后向前计算
         * 时间复杂度 O(rowIndex ^ 2) ，空间复杂度 O(1)
         */
        if (rowIndex < 0) {
            return {};
        }
        std::vector<int> ans(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};

int main() {
    auto res = Solution().getRow(5);
    for (auto o : res) {
        std::cout << o << ", ";
    }
    std::cout << std::endl;
    return 0;
}