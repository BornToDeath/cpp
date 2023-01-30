//
// Created by lixiaoqing on 2023/1/30.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /**
         * 方法：用哈希表建立双射关系，进行比较
         * 时间复杂度 O(m+n) ，空间复杂度 O(m+n)
         */
        std::unordered_map<char, std::string> m1;
        std::unordered_map<std::string, char> m2;
        int i = 0, j = 0, n = s.length();
        for (auto c: pattern) {
            if (i >= n) {
                return false;
            }
            while (i < n && s[i] == ' ') {
                ++i;
            }
            j = i;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            auto word = s.substr(i, j - i);
            bool f1 = m1.count(c) > 0, f2 = m2.count(word) > 0;
            if (f1 != f2 || f1 && f2 && m1[c] != word) {
                return false;
            }
            m1[c] = word;
            m2[word] = c;
            i = j;
        }
        while (i < n && s[i] == ' ') {
            ++i;
        }
        return i >= n;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::string pattern = "aaaa";
    std::string s = "dog cat cat dog";
    std::cout << Solution().wordPattern(pattern, s) << std::endl;
}