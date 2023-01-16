//
// Created by lixiaoqing on 2023/1/16.
//

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /**
         * 方法：两张哈希表，建立双射关系
         * 时间复杂度 O(n) ，空间复杂度 O(|E|) ，其中 E 是字符串的字符集
         */
        if (s.length() != t.length()) {
            return false;
        }
        std::map<char, char> m1, m2;
        for (int i = 0; i < s.length(); ++i) {
            auto x = s[i], y = t[i];
            if (m1.count(x) && m1[x] != y || m2.count(y) && m2[y] != x) {
                return false;
            }
            m1[x] = y;
            m2[y] = x;
        }
        return true;
    }
};

int main() {
    std::cout << std::boolalpha
              << Solution().isIsomorphic("egg", "add") << std::endl
              << Solution().isIsomorphic("foo", "bar") << std::endl
              << Solution().isIsomorphic("paper", "title") << std::endl
              << Solution().isIsomorphic("badc", "baba") << std::endl;
    return 0;
}