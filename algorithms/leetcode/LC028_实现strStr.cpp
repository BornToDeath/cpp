//
// Created by lixiaoqing on 2022/8/12.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        /**
         * 方法1：逐个字符比较
         * 时间复杂度 O(nm) ，空间复杂度 O(1)
         */
//        if (needle.empty()) {
//            return 0;
//        }
//        if (haystack.length() < needle.length()) {
//            return -1;
//        }
//        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
//            for (int j = 0, k = i; j < needle.length(); ++j, ++k) {
//                if (haystack[k] != needle[j]) {
//                    break;
//                }
//                if (j == needle.length() - 1) {
//                    return i;
//                }
//            }
//        }
//        return -1;

        /**
         * 方法2：KMP算法
         * 时间复杂度 O(n+m) ，空间复杂度 O(m)
         * 参考：https://leetcode.cn/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/
         */
        int n = haystack.length(), m = needle.length();
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return -1;
        }
        // 构建 next 数组。注意：构建出来的 next 数组表示前缀和后缀相同的字符的个数，所以在使用时需要取前一位的值
        std::vector<int> next(m, 0);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                ++j;
            }
            next[i] = j;
        }
//        print(next);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                // 回退到相同前缀之后的一个字符
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == m) {
                return i - j + 1;
            }
        }
        return -1;
    }
};

int main() {
//    std::cout << Solution().strStr("hello", "ll") << std::endl;
    std::cout << Solution().strStr("aaaab", "aab") << std::endl;
    return 0;
}