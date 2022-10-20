//
// Created by lixiaoqing on 2022/10/20.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        /**
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
        if (array.empty()) {
            return false;
        }
        int rows = array.size(), cols = array[0].size();
        for (int i = 0, j = cols - 1; i < rows && j >= 0;) {
            if (array[i][j] == target) {
                return true;
            } else if (array[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};



