//
// Created by lixiaoqing on 2022/10/20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        int i = 0, j = size - 1;
        while (i < j) {
            auto mid = (i + j) / 2;
            if (rotateArray[i] == rotateArray[mid] && rotateArray[mid] == rotateArray[j]) {
                ++i;
            } else if (rotateArray[mid] <= rotateArray[j]) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return rotateArray[i];
    }
};

int main() {
    std::cout << Solution().minNumberInRotateArray({1, 0, 1, 1, 1, 1, 1}) << std::endl;
    std::cout << Solution().minNumberInRotateArray({1, 1, 1, 1, 1, 0, 1}) << std::endl;
    return 0;
}
