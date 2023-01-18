//
// Created by lixiaoqing on 2022/4/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        /**
         * 方法1
         */
//        int max = 0;
//        for (int i = 0; i < n; ++i) {
//            max = max * 10 + 9;
//        }
//        std::vector<int> res;
//        for (int i = 1; i <= max; ++i) {
//            res.emplace_back(i);
//        }
//        return res;

        /**
         * 方法2
         */
        // 最大数是 10^n-1
        int max = pow(10, n) - 1;
        std::vector<int> res;
        for (int i = 1; i <= max; ++i) {
            res.emplace_back(i);
        }
        return res;
    }
};

int main() {
    auto res = Solution().printNumbers(3);
    std::for_each(res.begin(), res.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
    return 0;
}