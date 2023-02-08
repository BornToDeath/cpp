//
// Created by lixiaoqing on 2023/2/8.
//

#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        /**
         * 方法1：单指针
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            while (i < s.length() && s[i] != ' ') {
                ++i;
            }
            ++ans;
        }
        return ans;

        /**
         * 方法2：单指针的简洁写法
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                ++ans;
            }
        }
        return ans;

        /**
         * 方法3：利用 std::string find 方法
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int ans = 0;
        int pos = 0;
        while (pos != std::string::npos && (pos = s.find_first_not_of(' ', pos)) != std::string::npos) {
            ++ans;
            pos = s.find_first_of(' ', pos);
        }
        return ans;
    }
};