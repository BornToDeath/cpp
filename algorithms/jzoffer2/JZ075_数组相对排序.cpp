//
// Created by lixiaoqing on 2023/5/10.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        /*
         * 方法1: 计数排序的思想
         */
//        std::map<int, int> m;
//        for (auto n : arr1) {
//            if (m.count(n) == 0) {
//                m[n] = 1;
//            } else {
//                ++m[n];
//            }
//        }
//        std::vector<int> ans;
//        for (auto n : arr2) {
//            for (int i = 0; i < m[n]; ++i) {
//                ans.emplace_back(n);
//            }
//            m[n] = 0;
//        }
//        for (auto &pair: m) {
//            for (int i = 0; i < pair.second; ++i) {
//                ans.emplace_back(pair.first);
//            }
//        }
//        return ans;

        /*
         * 方法2: 自定义排序, arr2 其实相当于一种排序规则
         */
        std::unordered_map<int, int> m;
        for (int i = 0; i < arr2.size(); ++i) {
            m[arr2[i]] = i;
        }
        std::sort(arr1.begin(), arr1.end(), [&m](int x, int y) {
            /*
             * 1. 如果 x, y 都在 m 中, 比较其 m[x] 和 m[y] 的大小;
             * 2. 如果 x, y 只有一方在 m 中, 则在 m 中的较小;
             * 3. 如果 x, y 都不在 m 中, 则比较 x 和 y 的大小.
             */
            if (m.count(x)) {
                return m.count(y) == 0 || m[x] < m[y];
            } else {
                return m.count(y) != 1 && x < y;
            }
        });
        return arr1;
    }
};

int main() {
    std::vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    std::vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    auto ans = Solution().relativeSortArray(arr1, arr2);
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}