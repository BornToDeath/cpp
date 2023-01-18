//
// Created by lixiaoqing on 2022/8/17.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        /**
         * 方法1：递归
         */
//        if (n == 1) {
//            return "1";
//        }
//        std::string s = countAndSay(n - 1);
//        std::string ans;
//        int i = 0, len = s.length();
//        while (i < len) {
//            int j = i + 1;
//            while (j < len && s[i] == s[j]) {
//                ++j;
//            }
//            ans += std::to_string(j - i) + s[i];
//            i = j;
//        }
//        return ans;

        /**
         * 方法2：迭代
         */
        std::string s = "1";
        for (int k = 1; k < n; ++k) {
            std::string temp;
            int i = 0, len = s.length();
            while (i < len) {
                int j = i + 1;
                while (j < len && s[i] == s[j]) {
                    ++j;
                }
                temp += std::to_string(j - i) + s[i];
                i = j;
            }
            s = temp;
        }
        return s;
    }
};

int main() {
    std::cout << Solution().countAndSay(1) << std::endl;
    std::cout << Solution().countAndSay(2) << std::endl;
    std::cout << Solution().countAndSay(3) << std::endl;
    std::cout << Solution().countAndSay(4) << std::endl;
    std::cout << Solution().countAndSay(5) << std::endl;
    return 0;
}

