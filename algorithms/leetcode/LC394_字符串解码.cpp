//
// Created by lixiaoqing on 2022/7/26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        std::string ans;
        int pos = 0;
        while (pos < s.length()) {
            if (isDigit(s[pos])) {
                int k = 0;
                while (isDigit(s[pos])) {
                    k = 10 * k + (s[pos] - '0');
                    ++pos;
                }
                int i = pos + 1;
                int count = 1;
                while (count != 0) {
                    ++pos;
                    if (s[pos] == '[') {
                        ++count;
                    } else if (s[pos] == ']') {
                        --count;
                    }
                }
                // 递归解析
                auto temp = decodeString(s.substr(i, pos - i));
                while (k > 0) {
                    ans.append(temp);
                    --k;
                }
            } else {
                ans.push_back(s[pos]);
            }
            ++pos;
        }
        return ans;
    }

private:
    bool isDigit(char c) const {
        return c >= '0' && c <= '9';
    }
};

int main() {
    std::cout << Solution().decodeString("3[a]2[bc]") << std::endl;
    std::cout << Solution().decodeString("3[a2[c]]") << std::endl;
    std::cout << Solution().decodeString("2[abc]3[cd]ef") << std::endl;
    return 0;
}