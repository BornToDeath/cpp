//
// Created by lixiaoqing on 2022/6/7.
//

#include <vector>

using namespace std;

class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        /**
         * 方法1：
         */
//        return buildBST(vals, 0, vals.size() - 1);

        /**
         * 方法2：
         */
        int height = 0;
        int len = vals.size();
        while (len) {
            len /= 2;
            ++height;
        }
        return height;
    }

private:
    int buildBST(std::vector<int> &vals, int start, int end) {
        if (start > end) {
            return 0;
        }
        auto mid = (end - start) / 2 + start;
        auto left = buildBST(vals, start, mid - 1);
        auto right = buildBST(vals, mid + 1, end);
        return 1 + std::max(left, right);
    }
};