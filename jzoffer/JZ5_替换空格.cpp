//
// Created by lixiaoqing on 2022/4/11.
//

#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串
     */
    string replaceSpace(string s) {
        /**
         * 方法1：遍历字符串
         */
//        string res;
//        for (auto ch: s) {
//            if (ch == ' ') {
//                res.append("%20");
//            } else {
//                res.push_back(ch);
//            }
//        }
//        return res;

        /**
         * 方法2：使用 replace
         */
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                s.replace(i, 1, "%20");
            }
        }
        return s;
    }
};