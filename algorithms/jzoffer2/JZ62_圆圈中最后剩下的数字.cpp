//
// Created by lixiaoqing on 2023/3/31.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
         * 方法1: 利用数组
         * 时间复杂度 O(n ^ 2) , 空间复杂度 O(n)
         */
//        std::vector<bool> v(n, false);
//        const int SIZE = n;
//        int count = 0;
//        int i = -1;
//        while (n > 0) {
//            ++i;
//            i %= SIZE;
//            if (v[i]) {
//                continue;
//            }
//            ++count;
//            if (count == m) {
//                v[i] = true;
//                count = 0;
//                --n;
//                if (n == 0) {
//                    break;
//                }
//            }
//        }
//        return i;

        /*
         * 方法2：递归
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        if (n == 1) {
//            return 0;
//        }
//        auto x = lastRemaining(n - 1, m);
//        return (x + m) % n;

        /*
         * 方法3: 迭代
         * https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};

int main() {
    // 0, 1, 2, 3, 4
    std::cout << Solution().lastRemaining(5, 2) << std::endl;
    return 0;
}