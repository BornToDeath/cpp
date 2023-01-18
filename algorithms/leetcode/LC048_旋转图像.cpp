//
// Created by lixiaoqing on 2022/6/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int size = matrix.size();
        for (auto &arr:matrix) {
            std::reverse(arr.begin(), arr.end());
        }
        for (int i = 0; i < size; ++i) {
            for (int j = size - i - 1; j >= 0; --j) {
                std::swap(matrix[i][j], matrix[size - j - 1][size - i - 1]);
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution().rotate(matrix);
    for (auto &arr: matrix) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}