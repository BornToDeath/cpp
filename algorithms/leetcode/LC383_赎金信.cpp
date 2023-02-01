//
// Created by lixiaoqing on 2023/2/1.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> arr(26, 0);
        for (auto c: magazine) {
            ++arr[c - 'a'];
        }
        for (auto c: ransomNote) {
            if (--arr[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};