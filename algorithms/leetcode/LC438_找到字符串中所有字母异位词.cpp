//
// Created by lixiaoqing on 2022/8/5.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /**
         * 方法1：利用 unordered_multiset + 滑动窗口
         */
//        if (s.length() < p.length()) {
//            return {};
//        }
//        std::unordered_multiset<char> _set;
//        for (auto ch: p) {
//            _set.insert(ch);
//        }
//        std::vector<int> ans;
//        int i, j;
//        for (i = 0; i <= s.length() - p.length(); ++i) {
//            if (_set.count(s[i]) == 0) {
//                continue;
//            }
//            std::unordered_multiset<char> set(_set);
//            for (j = i; j < i + p.length(); ++j) {
//                if (set.count(s[j]) == 0) {
//                    break;
//                }
//                set.erase(set.find(s[j]));
//            }
//            if (j - i == p.length()) {
//                ans.push_back(i);
//                while (j < s.length() && s[i++] == s[j++]) {
//                    ans.push_back(i);
//                }
//            }
//            if (_set.count(s[j]) == 0) {
//                i = j;
//            }
//        }
//        return ans;

        /**
         * 方法2：滑动窗口，统计滑动窗口内不同字符的数量
         */
//        int sLen = s.length(), pLen = p.length();
//        if (sLen < pLen) {
//            return {};
//        }
//        std::vector<int> ans;
//        std::vector<int> sCount(26), pCount(26);
//        for (int i = 0; i < pLen; ++i) {
//            ++sCount[s[i] - 'a'];
//            ++pCount[p[i] - 'a'];
//        }
//        if (sCount == pCount) {
//            ans.emplace_back(0);
//        }
//        for (int i = 0; i < sLen - pLen; ++i) {
//            --sCount[s[i] - 'a'];
//            ++sCount[s[i + pLen] - 'a'];
//            if (sCount == pCount) {
//                ans.emplace_back(i + 1);
//            }
//        }
//        return ans;

        /**
         * 方法3：在方法2的基础上进行优化，统计滑动窗口内字符和 p 中字符有差别的字符的数量
         */
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen) {
            return {};
        }
        std::vector<int> ans;
        std::vector<int> diff(26);
        for (int i = 0; i < pLen; ++i) {
            ++diff[s[i] - 'a'];
            --diff[p[i] - 'a'];
        }
        int differ = diff.size() - std::count(diff.begin(), diff.end(), 0);
        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            if (diff[s[i] - 'a'] == 0) {  // 现在为0，后面diff减一，不相同的字符变多了，所以 differ 需要加 1
                ++differ;
            } else if (diff[s[i] - 'a'] == 1) {  // 现在为1，后面diff减一，不相同的字符变少了，所以 differ 需要减 1
                --differ;
            }
            --diff[s[i] - 'a'];

            if (diff[s[i + pLen] - 'a'] == 0) {  // 现在为0，后面diff加一，不相同的字符变多了，所以 differ 需要加 1
                ++differ;
            } else if (diff[s[i + pLen] - 'a'] == -1) {  // 现在为-1，后面diff加一，不相同的字符变少了，所以 differ 需要减 1
                --differ;
            }
            ++diff[s[i + pLen] - 'a'];

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().findAnagrams("abab", "ab");
//    auto ans = Solution().findAnagrams("cbaebabacd", "abc");
//    auto ans = Solution().findAnagrams("baa", "aa");
    for (auto e: ans) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    return 0;
}