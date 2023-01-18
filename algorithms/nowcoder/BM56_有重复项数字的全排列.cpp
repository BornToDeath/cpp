//
// Created by lixiaoqing on 2022/5/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        permute(num, 0);
        if (!res.empty()) {
            std::sort(res.begin(), res.end());
        }
        return res;
    }

private:
    void permute(vector<int> &num, int index) {
        if (index == num.size() - 1) {
            if (std::find(res.begin(), res.end(), num) == res.end()) {
                res.push_back(num);
            }
            return;
        }
        for (auto i = index; i < num.size(); ++i) {
            swap(num[i], num[index]);
            permute(num, index + 1);
            swap(num[i], num[index]);
        }
    }

private:
    vector<vector<int>> res;
};

int main() {
    vector<int> nums = {2, -1, 3};
    auto res = Solution().permuteUnique(nums);
    for (auto &ele: res) {
        for (auto num: ele) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}