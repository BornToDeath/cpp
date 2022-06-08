//
// Created by lixiaoqing on 2022/6/8.
//

#include <iostream>
#include <vector>
using namespace std;

class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        if (A.empty()) {
            return -1;
        }
        int sum = 0, max = A[0];
        for (auto num: A) {
            sum += num;
            max = std::max(sum, max);
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> arr = {-1, -2, 10, -10, 5};
    std::cout << MaxSum().getMaxSum(arr, arr.size()) << std::endl;
    return 0;
}