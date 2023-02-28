//
// Created by lixiaoqing on 2023/2/28.
//

#include <vector>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        std::unordered_map<int, int> _map;
        std::stack<int> _stack;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            const auto num = nums2[i];
            while (!_stack.empty() && num >= _stack.top()) {
                _stack.pop();
            }
            _map[num] = _stack.empty() ? -1 : _stack.top();
            _stack.push(num);
        }
        int n = nums1.size();
        std::vector<int> ans(n);
        for (auto i = 0; i < n; ++i) {
            ans[i] = _map[nums1[i]];
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums1 = {2, 4};
    std::vector<int> nums2 = {1, 2, 3, 4};
    auto ans = Solution().nextGreaterElement(nums1, nums2);
    for (auto c: ans) {
        std::cout << c << ", ";
    }
    std::cout << std::endl;
    return 0;
}