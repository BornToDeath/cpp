//
// Created by lixiaoqing on 2022/5/16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.empty()) {
            return {};
        }
        permute(num, 0);
        return res;
    }

private:
    void permute(vector<int> &num, int index) {
        if (index == num.size() - 1) {
            res.push_back(num);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            swap(num[i], num[index]);
            permute(num, index + 1);
            swap(num[i], num[index]);
        }
    }

private:
    vector<vector<int>> res;
};

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = Solution().permute(nums);
    for (auto ele:res) {
        for (auto num:ele) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}