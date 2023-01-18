//
// Created by lixiaoqing on 2022/6/7.
//

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    /**
     *
     * @param num int整型
     * @return string字符串
     */
    string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> MAP = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"},
        };
        std::string res;
        while (num) {
            for (auto &ele : MAP) {
                if (num >= ele.first) {
                    res.append(ele.second);
                    num -= ele.first;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    std::cout << Solution().intToRoman(1996) << std::endl;
    return 0;
}