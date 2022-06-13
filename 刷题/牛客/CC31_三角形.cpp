//
// Created by lixiaoqing on 2022/6/13.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += std::min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
//            print(triangle[i]);
        }
        return *std::min_element(triangle[len - 1].begin(), triangle[len - 1].end());
    };å
};

int main() {
    std::vector<std::vector<int>> mat = {
            {20},
            {30, 40},
            {60, 50, 70},
            {40, 10, 80, 30}
    };
    std::cout << Solution().minimumTotal(mat) << std::endl;
}