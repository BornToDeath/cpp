//
// Created by lixiaoqing on 2022/5/7.
//

#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
    bool judge(string str) {
        auto len = str.length();
        for (int i = 0; i < len / 2; ++i) {
            if (str[i] != str[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};