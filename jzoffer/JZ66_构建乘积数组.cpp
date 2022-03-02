//
// Created by lixiaoqing on 2021/12/10.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void printArray(const vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](int elem) { std::cout << elem << ", "; });
    std::cout << std::endl;
}

class Solution {
public:
    vector<int> multiply(const vector<int> &A) {
        const int product = std::accumulate(A.begin(), A.end(), 1, [](int base, int num) {
            return (num == 0) ? base : (base * num);
        });
        vector<int> res(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != 0) {
                res[i] = product / A[i];
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {10, 0, 5, 2};
    printArray(nums);

    Solution solution;
    auto ret = solution.multiply(nums);
    printArray(ret);

    return 0;
}