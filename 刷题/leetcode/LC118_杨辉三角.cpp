//
// Created by lixiaoqing on 2022/8/23.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /**
         * 方法1
         */
//        std::vector<std::vector<int>> ans = {{1}};
//        if (numRows == 1) {
//            return ans;
//        }
//        for (int i = 1; i < numRows; ++i) {
//            auto pre = ans[i - 1];
//            std::vector<int> v(pre.size() + 1, 1);
//            for (int j = 1; j < v.size() - 1; ++j) {
//                v[j] = pre[j - 1] + pre[j];
//            }
//            ans.emplace_back(v);
//        }
//        return ans;

        /**
         * 方法2：效率更高
         */
        std::vector<std::vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

void print(std::vector<std::vector<int>> &mat) {
    for (auto &arr: mat) {
        for (auto num: arr) {
            printf("%d, ", num);
        }
        printf("\n");
    }
}

int main() {
    auto mat = Solution().generate(5);
    print(mat);
    return 0;
}