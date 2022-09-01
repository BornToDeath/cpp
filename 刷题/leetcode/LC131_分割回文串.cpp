//
// Created by lixiaoqing on 2022/8/31.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        /**
         * 方法：回溯 + 判断是否是回文串。
         * 时间复杂度 O(n * 2^n) ，空间复杂度 O(n^2)
         * 判断是否是回文串时有个小技巧，一般是使用双指针从首尾两端向中间靠拢来判断，这种方法存在重复计算的情况，所以可以动态规划
         * 计算出 s 中每个子串是否是回文串，然后在需要时直接取结果。
         * 设 f(i, j) 表示 s[i...j] 是否为回文串，那么有状态转移方程：
         *   f(i, j) =| true,                           i >= j
         *            | (s[i] == s[j]) && f(i+1, j-1),  otherwise
         */
        const int n = s.length();
        f.assign(n, std::vector<int>(n, 0));
        partition(s, 0);
        return ans;
    }

private:
    // 回溯
    void partition(std::string &s, int pos) {
        if (pos >= s.length()) {
            if (!v.empty()) {
                ans.emplace_back(v);
            }
        }
        for (int i = pos; i < s.length(); ++i) {
            if (isPalindrome(s, pos, i)) {
                v.push_back(s.substr(pos, i - pos + 1));
                partition(s, i + 1);
                v.pop_back();
            }
        }
    }

    // 判断是否是回文串
    int isPalindrome(std::string &s, int i, int j) {
        /**
         * 方法1：双指针解法
         */
//        while (i < j) {
//            if (s[i] != s[j]) {
//                return false;
//            }
//            ++i, --j;
//        }
//        return true;

        /**
         * 方法2：动态规划，带记忆
         */
        if (f[i][j] != 0) {
            return f[i][j];
        }
        if (i >= j) {
            return 1;
        }
        return f[i][j] = (s[i] == s[j]) && isPalindrome(s, i + 1, j - 1);
    }

private:
    // 回文串集合
    std::vector<std::vector<std::string>> ans;
    // 记录每次迭代的回文串
    std::vector<std::string> v;
    // f[i][j] 表示 s[i...j]是否是回文串，1：是，-1：不是，0：未搜索
    std::vector<std::vector<int>> f;
};

int main() {
    auto ans = Solution().partition("aaa");
    for (auto &arr: ans) {
        for (auto &s: arr) {
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}