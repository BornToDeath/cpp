//
// Created by lixiaoqing on 2022/6/17.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string str;
        generate(n, 0, 0, str, res);
        return res;
    }

private:
    /**
     *
     * @param n
     * @param left  表示已经用的左括号的个数
     * @param right 表示已经用的右括号的个数
     * @param str
     * @param res
     */
    void generate(int n, int left, int right, std::string &str, std::vector<std::string> &res) {
//        printf("%d, %d, %s\n", left, right, str.c_str());
        if (left == n && right == n) {
            res.emplace_back(str);
            return;
        }
        if (left < n) {
            str.push_back('(');
            generate(n, left + 1, right, str, res);
            str.pop_back();
        }
        if (left > right) {
            str.push_back(')');
            generate(n, left, right + 1, str, res);
            str.pop_back();
        }
    }
};

int main() {
    auto res = Solution().generateParenthesis(3);
    for (auto &str: res) {
        std::cout << str << ", ";
    }
    std::cout << std::endl;
    return 0;
}