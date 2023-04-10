//
// Created by lixiaoqing on 2023/3/10.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> printNumbers(int n) {
        std::vector<int> ans;
        int num = 1;
        while (n) {
            for (int i = num; i <= num * 10 - 1; ++i) {
                ans.emplace_back(i);
            }
            num *= 10;
            --n;
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().printNumbers(3);
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}