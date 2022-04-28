//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include <vector>

using namespace std;

inline void print(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int i = 0;
        int j = array.size() - 1;
        while (i < j) {
            auto temp = array[i] + array[j];
            if (temp == sum) {
                return {array[i], array[j]};
            }
            temp < sum ? ++i : --j;
        }
        return {};
    }
};

int main() {
    std::vector<int> array = {1, 2, 4, 7, 11, 15};
    print(Solution().FindNumbersWithSum(array, 15));
    return 0;
}