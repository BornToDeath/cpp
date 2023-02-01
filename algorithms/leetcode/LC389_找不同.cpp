//
// Created by lixiaoqing on 2023/2/1.
//

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        /**
         * 方法1：数组计数
         * 时间复杂度 O(m + n) ，空间复杂度 O(|S|) ，其中 |S| 是字符集的长度 26
         */
//        std::vector<int> letters(26);
//        for (char c: t) {
//            ++letters[c - 'a'];
//        }
//        for (char c: s) {
//            --letters[c - 'a'];
//        }
//        for (int i = 0; i < letters.size(); ++i) {
//            if (letters[i] == 1) {
//                return i + 'a';
//            }
//        }
//        return ' ';

        /**
         * 方法2：求和
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
//        int sum = 0;
//        for (auto c: t) {
//            sum += c;
//        }
//        for (auto c: s) {
//            sum -= c;
//        }
//        return sum;

        /**
         * 方法2：异或
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
        int num = 0;
        for (auto c: s) {
            num ^= c;
        }
        for (auto c: t) {
            num ^= c;
        }
        return num;
    }
};

int main() {
    std::cout << Solution().findTheDifference("abcd", "abcde") << std::endl;
    std::cout << Solution().findTheDifference("a", "aa") << std::endl;
    return 0;
}