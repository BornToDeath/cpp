//
// Created by lixiaoqing on 2023/4/26.
//

#include <iostream>
#include <string>
#include <array>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t || s.length() != t.length()) {
            return false;
        }
        std::array<int, 26> arr{};
        for (int i = 0; i < s.length(); ++i) {
            ++arr[s[i] - 'a'];
            --arr[t[i] - 'a'];
        }
        return std::all_of(arr.begin(), arr.end(), [](int num) { return num == 0; });
    }
};

int main() {
    std::cout << Solution().isAnagram("abbb", "bbba") << std::endl;
    std::cout << Solution().isAnagram("abbb", "bbbb") << std::endl;
    std::cout << Solution().isAnagram("abbb", "bbbba") << std::endl;
    return 0;
}