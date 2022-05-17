//
// Created by lixiaoqing on 2022/5/17.
//

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     *
     * @param n int整型
     * @return string字符串vector
     */
    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return res;
    }

private:
    /**
     * 递归
     * @param str
     * @param usedLeft  左括号使用次数
     * @param usedRight 右括号使用次数
     * @param n
     */
    void generate(std::string str, int usedLeft, int usedRight, int n) {
        if (usedLeft == n && usedRight == n) {
            res.emplace_back(str);
            return;
        }
        if (usedLeft < n) {
            generate(str + '(', usedLeft + 1, usedRight, n);
        }
        if (usedRight < n && usedRight < usedLeft) {
            generate(str + ')', usedLeft, usedRight + 1, n);
        }
    }

private:
    vector<string> res;
};

int main() {
    auto res = Solution().generateParenthesis(3);
    for (auto str: res) {
        printf("%s, ", str.c_str());
    }
    printf("\n");
    return 0;
}