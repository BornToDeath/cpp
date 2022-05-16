//
// Created by lixiaoqing on 2022/5/16.
//

#include <iostream>
#include <vector>

using namespace std;

void print(const std::vector<int> &arr) {
    for (auto ele: arr) {
        std::cout << ele << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        std::vector<std::vector<int>> res;
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                if (num[i] + num[j] + num[k] == 0) {
                    std::vector<int> ele = {num[i], num[j], num[k]};
                    if (std::find(res.begin(), res.end(), ele) == res.end()) {
                        res.emplace_back(ele);
                    }
                    ++j;
                    --k;
                } else if (num[i] + num[j] + num[k] < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return res;
    }
};

int main() {
//    std::vector<int> nums = {-10, 0, 10, 20, -10, -40};
    std::vector<int> nums = {0, 10, 10, 10, 0, -10, -10, -10};
    auto res = Solution().threeSum(nums);
    if (!res.empty()) {
        for (auto ele: res) {
            for (auto num: ele) {
                std::cout << num << ", ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "结果为空！" << std::endl;
    }

    return 0;
}