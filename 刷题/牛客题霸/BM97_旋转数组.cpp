//
// Created by lixiaoqing on 2022/5/26.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](int num) {
        std::cout << num << ", ";
    });
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int> &a) {
        /**
         * 方法1：逐轮后移
         */
//        if (a.empty()) {
//            return {};
//        }
//        m %= n;
//        for (int i = 0; i < m; ++i) {
//            auto ele = a[n - 1];
//            for (int j = n - 1; j >= 1; --j) {
//                a[j] = a[j - 1];
//            }
//            a[0] = ele;
//        }
//        return a;

        /**
         * 方法2：利用 std::reverse
         */
        if (a.empty() || m % n == 0) {
            return a;
        }
        m %= n;
        // 先整体反转
        std::reverse(a.begin(), a.end());
        // 再反转前m个
        std::reverse(a.begin(), a.begin() + m);
        // 再反转剩余的
        std::reverse(a.begin() + m, a.end());
        return a;
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(arr);
    int n = arr.size();
    int m = 3;
    auto res = Solution().solve(n, m, arr);
    print(res);
    return 0;
}