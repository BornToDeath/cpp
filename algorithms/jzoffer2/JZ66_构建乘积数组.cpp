//
// Created by lixiaoqing on 2023/4/6.
//

#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        /*
         * 方法: 先从前向后计算前半部分乘积，再从后向前计算后半部分乘积
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        if (a.empty()) {
            return {};
        }
        const int size = a.size();
        std::vector<int> ans(size, 1);
        for (int i = 1; i < size; ++i) {
            ans[i] = ans[i - 1] * a[i - 1];
        }
        int backward = 1;
        for (int i = size - 2; i >= 0; --i) {
            backward *= a[i + 1];
            ans[i] *= backward;
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    auto ans = Solution().constructArr(nums);
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}