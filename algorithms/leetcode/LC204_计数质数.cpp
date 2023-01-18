//
// Created by lixiaoqing on 2022/9/26.
//

#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        /**
         * 方法1：枚举，利用 set 存储质数
         * 时间复杂度 O(nm) ，空间复杂度 O(m) ，其中 m 是质数的个数
         */
//        if (n <= 2) {
//            return 0;
//        }
//        std::set<int> _set;
//        _set.insert(2);
//        for (int i = 3; i < n; i += 2) {
//            bool flag = false;
//            for (auto e: _set) {
//                if (i % e == 0) {
//                    flag = true;
//                    break;
//                }
//            }
//            if (!flag) {
//                _set.insert(i);
//            }
//        }
//        return _set.size();

        /**
         * 方法2：枚举
         * 时间复杂度 O(n * sqrt(n)) ，空间复杂度 O(1)
         */
//        int count = 0;
//        auto isPrime = [](int n) -> bool {
//            // 如果不是质数，则在 [2, sqrt(n)] 范围内一定有因数
//            for (int i = 2; i * i <= n; ++i) {
//                if (n % i == 0) {
//                    return false;
//                }
//            }
//            return true;
//        };
//        for (int i = 2; i < n; ++i) {
//            if (isPrime(i)) {
//                ++count;
//            }
//        }
//        return count;

        /**
         * 方法3：埃氏筛，见：https://leetcode.cn/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/
         * 时间复杂度 O(nloglogn) ，空间复杂度 O(n)
         */
        if (n <= 2) {
            return 0;
        }
        int count = 0;
        std::vector<bool> primes(n + 1, true);
        for (int i = 2; i < n; ++i) {
            if (!primes[i]) {
                continue;
            }
            ++count;
            for (int j = 2 * i; j < n; j += i) {
                primes[j] = false;
            }
        }
        return count;
    }
};

int main() {
    std::cout << Solution().countPrimes(10) << std::endl;
    return 0;
}