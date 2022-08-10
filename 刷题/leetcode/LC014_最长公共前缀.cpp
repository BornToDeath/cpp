//
// Created by lixiaoqing on 2022/8/10.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        /**
         * 方法1：逐个字母比较
         * 时间复杂度 O(nm) ，空间复杂度 O(1)
         */
//        if (strs.empty()) {
//            return "";
//        }
//        for (int pos = 0; pos < strs[0].length(); ++pos) {
//            auto ch = strs[0][pos];
//            for (auto &str: strs) {
//                if (str[pos] != ch) {
//                    return strs[0].substr(0, pos);
//                }
//            }
//        }
//        return strs[0];

        /**
         * 方法2：先对所有字符串进行排序，然后取首尾字符串进行比较
         * 时间复杂度 O(mnlogn) ，空间复杂度 O(1)
         */
        if (strs.empty()) {
            return "";
        }
        std::string a = "123", b = "123";
        bool f = a < b;
        std::sort(strs.begin(), strs.end());
        auto firstStr = strs[0], lastStr = strs[strs.size() - 1];
        int pos = 0;
        for (; pos < firstStr.length() && pos < lastStr.length(); ++pos) {
            if (firstStr[pos] != lastStr[pos]) {
                break;
            }
        }
        return firstStr.substr(0, pos);
    }
};