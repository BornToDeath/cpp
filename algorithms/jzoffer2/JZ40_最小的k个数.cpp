//
// Created by lixiaoqing on 2023/3/20.
//

#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        /**
         * 方法1：排序
         * 时间复杂度 O(nlogn) ，空间复杂度 O(logn)
         */
        std::sort(arr.begin(), arr.end());
        std::vector<int> ans(k);
        for (int i = 0; i < arr.size() && i < k; ++i) {
            ans[i] = arr[i];
        }
        return ans;

        /**
         * 方法2：借助堆
         * 时间复杂度 O(nlogk) ，空间复杂度 O(k)
         */
//        if (k <= 0) {
//            return {};
//        }
//        if (arr.size() <= k) {
//            return arr;
//        }
//
//        std::priority_queue<int> q;
//        for (auto n: arr) {
//            if (q.size() < k) {
//                q.push(n);
//            } else if (q.top() > n) {
//                q.pop();
//                q.push(n);
//            }
//        }
//        int n = q.size();
//        std::vector<int> ans(n);
//        while (!q.empty()) {
//            ans[--n] = q.top();
//            q.pop();
//        }
//        return ans;
    }
};