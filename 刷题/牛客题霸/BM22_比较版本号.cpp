//
// Created by lixiaoqing on 2022/5/10.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    int compare(string version1, string version2) {
        /**
         * 方法1：将字符串按'.'分割取整，并比较大小
         */
//        while (!version1.empty() || !version2.empty()) {
//            auto v1 = getFirstVersion(version1);
//            auto v2 = getFirstVersion(version2);
//            if (v1 > v2) {
//                return 1;
//            } else if (v1 < v2) {
//                return -1;
//            }
//        }
//        return 0;

        /**
         * 方法2：双指针
         */
        int pos1 = 0, pos2 = 0;
        while (pos1 < version1.length() || pos2 < version2.length()) {
            int v1 = 0, v2 = 0;
            while (pos1 < version1.length() && version1[pos1] != '.') {
                v1 = v1 * 10 + (version1[pos1] - '0');
                ++pos1;
            }
            ++pos1;
            while (pos2 < version2.length() && version2[pos2] != '.') {
                v2 = v2 * 10 + (version2[pos2] - '0');
                ++pos2;
            }
            ++pos2;
            if (v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
        }
        return 0;
    }

private:
    int getFirstVersion(std::string &str) {
        if (str.empty()) {
            return 0;
        }
        auto pos = str.find_first_of('.');
        if (pos == std::string::npos) {
            pos = str.length();
        }
        auto version = std::stoi(str.substr(0, pos));
        if (pos == str.length()) {
            str = "";
        } else {
            str = str.substr(pos + 1);
        }
        return version;
    }
};

int main() {
    std::string str1 = "0.0226";
    std::string str2 = "0.1";
    std::cout << Solution().compare(str1, str2) << std::endl;
    return 0;
}