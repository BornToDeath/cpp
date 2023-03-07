//
// Created by lixiaoqing on 2023/3/7.
//

#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string replaceSpace(string s) {
        /**
         * 方法1：利用 std::string.insert() 方法
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] == ' ') {
//                s.replace(i, 1, "%20");
//                i += 2;
//            }
//        }
//        return s;

        /**
         * 方法2：先统计空格个数，预先分配字符串长度
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        auto count = std::count_if(s.begin(), s.end(), [](char c) { return c == ' '; });
        int len = s.length();
        s.resize(len + count * 2);
        for (int i = len - 1, j = s.length() - 1; i != j; --i) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
        }
        return s;
    }
};


int main() {
    std::string s = "We are happy.";
    std::cout << Solution().replaceSpace(s) << std::endl;
    return 0;
}