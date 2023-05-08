//
// Created by lixiaoqing on 2023/5/8.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        if (arr.empty()) {
            return -1;
        }
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            auto mid = ((j - i) >> 1) + i;
            if (arr[mid] < arr[mid + 1]) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return j;
    }
};

int main() {
    std::vector<int> arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    arr = {0, 1, 0};
    arr = {1, 3, 5, 4, 2};
    arr = {0, 10, 5, 2};
    arr = {3, 4, 5, 1};
    std::cout << Solution().peakIndexInMountainArray(arr) << std::endl;
    return 0;
}