//
// Created by boss on 2024/1/9.
//

#include <iostream>

using std::string;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) {
            return false;
        }
        auto is_upper = [](char c) { return std::isupper(c, std::locale()); };
        auto is_lower = [](char c) { return std::islower(c, std::locale()); };
        if (word.length() == 1) {
            return is_upper(word.front());
        }
        if (isupper(word.front())) {
            return std::all_of(std::next(word.begin()), word.end(), is_upper) ||
                   std::all_of(std::next(word.begin()), word.end(), is_lower);
        } else {
            return std::all_of(word.begin(), word.end(), is_lower);
        }
    }
};