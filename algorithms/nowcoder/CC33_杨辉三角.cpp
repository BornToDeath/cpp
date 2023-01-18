//
// Created by lixiaoqing on 2022/6/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param numRows int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > generate(int numRows) {
        if (numRows <= 0) {
            return {};
        }
        std::vector<std::vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> v(i + 1, 1);
            for (int j = 1; j <= i - 1; ++j) {
                v[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.emplace_back(v);
        }
        return res;
    }
};