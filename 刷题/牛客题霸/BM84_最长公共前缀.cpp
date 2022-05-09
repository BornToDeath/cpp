//
// Created by lixiaoqing on 2022/5/9.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string> &strs) {
        /**
         * 方法1：找长度最小字符串，然后将其与其他字符串一一比较
         */
//        if (strs.empty()) {
//            return "";
//        }
//        std::string base = strs[0];
//        for (const auto &str: strs) {
//            if (str.length() < base.length()) {
//                base = str;
//            }
//        }
//
//        bool flag = false;
//        while (!base.empty() && !flag) {
//            for (int i = 0; i < strs.size(); ++i) {
//                if (strs[i].find(base) == string::npos) {
//                    base.pop_back();
//                    break;
//                }
//                if (i == strs.size() - 1) {
//                    flag = true;
//                }
//            }
//        }
//        return base;

        /**
         * 方法2：依次比较每一个字符
         */

        /**
         * 方法3：先对字符串进行排序， 然后比较首尾两个字符串
         */
        if (strs.empty()) {
            return "";
        }
        std::sort(strs.begin(), strs.end());
        auto s1 = strs.front();
        auto s2 = strs.back();
        int len = s1.length() < s2.length() ? s1.length() : s2.length();
        int pos = 0;
        for (; pos < len; ++pos) {
            if (s1[pos] != s2[pos]) {
                break;
            }
        }
        return s1.substr(0, pos);
    }
};

int main() {
    std::vector<std::string> strs = {"abca", "abc", "abca", "abc", "abcc"};
    std::cout << Solution().longestCommonPrefix(strs) << std::endl;
    return 0;
}