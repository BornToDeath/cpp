//
// Created by lixiaoqing on 2022/3/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty()) {
            return false;
        }
        // 从右上角开始查找
        int height = 0;
        int width = array[0].size() - 1;
        while (height < array.size() && width >= 0) {
            auto num = array[height][width];
            if (num == target) {
                return true;
            }
            if (num < target) {
                ++height;
            } else {
                --width;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> arr = {
            {1, 2, 8,  9},
            {2, 4, 9,  12},
            {4, 7, 10, 13},
            {6, 8, 11, 15}
    };
    Solution solution;
    std::cout << std::boolalpha;
    std::cout << solution.Find(7, arr) << std::endl;

}