//
// Created by lixiaoqing on 2023/7/3.
//

#include <vector>
#include <string>
#include <iostream>

using std::vector;

class Solution {
public:
    int compress(vector<char> &chars) {
        /*
         * 方法: 双指针
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int pos = 0;
        for (int i = 0; i < chars.size();) {
            int j = i;
            while (j < chars.size() && chars[j] == chars[i]) {
                ++j;
            }
            chars[pos++] = chars[i];
            if (j - i > 1) {
                std::string s = std::to_string(j - i);
                for (auto c: s) {
                    chars[pos++] = c;
                }
            }
            i = j;
        }
        chars.erase(chars.begin() + pos, chars.end());
        return pos;
    }
};

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    std::cout << Solution().compress(chars) << std::endl;
    for (auto c: chars) {
        std::cout << c << ", ";
    }
    std::cout << std::endl;
    return 0;
}