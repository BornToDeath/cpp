//
// Created by lixiaoqing on 2023/6/1.
//

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string compressString(string S) {
        std::string ans;
        for (int i = 0; i < S.length();) {
            int j = i;
            while (j < S.length() && S[i] == S[j]) {
                ++j;
            }
            ans.push_back(S[i]);
            ans.append(std::to_string(j - i));
            if (ans.length() >= S.length()) {
                return S;
            }
            i = j;
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().compressString("aabcccccaaa") << std::endl;
    std::cout << Solution().compressString("abbccd") << std::endl;
    return 0;
}