//
// Created by lixiaoqing on 2022/6/26.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        /**
         * 方法1：时间复杂度O(nlogn)，空间复杂度O(1)
         */
//        std::vector<int> ans;
//        for (int i = 0; i <= n; ++i) {
//            int num = i, count = 0;
//            while (num) {
//                if ((num & 0x1) == 1) {
//                    ++count;
//                }
//                num >>= 1;
//            }
//            ans.emplace_back(count);
//        }
//        return ans;

        /**
         * 方法2：时间复杂度O(n)，空间复杂度O(1)
         */
//        std::vector<int> ans(n + 1, 0);
//        for (int i = 1; i <= n; ++i) {
//            if (i == 1) {
//                ans[i] = 1;
//            } else {
//                ans[i] = ans[(i >> 1)] + (i & 0x1);
//            }
//        }
//        return ans;

        /**
         * 方法3：时间复杂度O(n)，空间复杂度O(1)
         */
        std::vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().countBits(16);
    for (auto num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}