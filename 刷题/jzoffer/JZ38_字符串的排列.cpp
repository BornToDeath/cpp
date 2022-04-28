//
// Created by lixiaoqing on 2022/3/21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArray(const std::vector<std::string> &arr) {
    for (const auto ele: arr) {
        std::cout << ele << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    vector<string> Permutation(string str) {
        /**
         * 方法1
         */
//        if (str.empty()) {
//            return {};
//        }
//        // 计算所有排列
//        permutation(str);
//        // 排序
//        std::sort(res.begin(), res.end());
//        // 去除重复元素
//        res.erase(std::unique(res.begin(), res.end()), res.end());
//        return res;

        /**
         * 方法2
         */
        if (str.empty()) {
            return {};
        }
        std::vector<std::string> strs;
        permutation2(str, strs, 0);
        return strs;
    }

private:
    void permutation2(std::string str, std::vector<std::string> &strs, int index) {
        if (index == str.length() - 1) {
            // 去除重复元素
            if (std::find(strs.begin(), strs.end(), str) == strs.end()) {
                strs.push_back(str);
            }
            return;
        }
        for (int i = index; i < str.size(); ++i) {
            swap(str, i, index);
            permutation2(str, strs, index + 1);
            swap(str, i, index);
        }
    }

    void permutation(std::string str) {
        if (str.empty()) {
            res.push_back(sss);
            return;
        }
        for (int i = 0; i < str.size(); ++i) {
            // 固定第一个字符，后面的字符串递归
            sss.push_back(str[i]);
            swap(str, 0, i);
            permutation(str.substr(1));
            swap(str, 0, i);
            sss.pop_back();
        }
    }

    void swap(std::string &str, int i, int j) {
        auto ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }

private:
    std::string sss;
    std::vector<std::string> res;
};

int main() {
    std::string str = "aab";
    Solution solution;
    auto res = solution.Permutation(str);
    std::cout << "================" << std::endl;
    printArray(res);
    return 0;
}