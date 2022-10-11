//
// Created by lixiaoqing on 2022/10/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return -1;
        }
        int max = array[0], sum = 0;
        for (auto e: array) {
            if (sum + e >= 0) {
                sum += e;
            } else {
                sum = e;
            }
            max = std::max(max, sum);
            sum = sum < 0 ? 0 : sum;
        }
        return max;
    }
};

int main() {
    std::vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    array = {-10, -1, -3};
    std::cout << Solution().FindGreatestSumOfSubArray(array) << std::endl;
    return 0;
}