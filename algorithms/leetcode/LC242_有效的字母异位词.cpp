//
// Created by lixiaoqing on 2022/9/2.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /**
         * 方法1：借助 std::sort
         * 时间复杂度 O(mlogm + nlogn) ，空间复杂度 O(logm + logn) ，快排需要 logn 的时间复杂度
         */
//        std::sort(s.begin(), s.end());
//        std::sort(t.begin(), t.end());
//        return s == t;

        /**
         * 方法2：借助 std::unordered_map
         * 时间复杂度 O(m + n) ，空间复杂度 O(m)
         */
//        if (s.length() != t.length()) {
//            return false;
//        }
//        std::unordered_map<char, int> map;
//        for (auto c: s) {
//            ++map[c];
//        }
//        for (auto c: t) {
//            if (map.count(c) == 0 || --map[c] < 0) {
//                return false;
//            }
//        }
//        return true;

        /**
         * 方法3：借助数组
         * 时间复杂度 O(m + n) ，空间复杂度 O(k) ，其中 k=26
         */
        if (s.length() != t.length()) {
            return false;
        }
        int dp[26]{};
        for (auto c: s) {
            ++dp[c - 'a'];
        }
        for (auto c: t) {
            if (dp[c - 'a']-- <= 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isAnagram("car", "rac") << std::endl;
    std::cout << Solution().isAnagram("car", "tac") << std::endl;
    return 0;
}