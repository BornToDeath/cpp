//
// Created by lixiaoqing on 2023/2/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        /**
         * 方法：时间复杂度 O(mlogm + nlogn) ，空间复杂度 O(logm + logn)
         */
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; count < g.size() && i < s.size(); ++i) {
            if (g[count] <= s[i]) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> g = {1, 2};
    std::vector<int> s = {1, 2, 3};
    std::cout << Solution().findContentChildren(g, s) << std::endl;
    return 0;
}