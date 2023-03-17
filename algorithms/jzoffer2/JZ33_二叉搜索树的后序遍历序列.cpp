//
// Created by lixiaoqing on 2023/3/17.
//

#include <vector>

using std::vector;

class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }

private:
    bool verifyPostorder(std::vector<int> &postorder, int start, int end) {
        if (start >= end) {
            return true;
        }
        const auto base = postorder[end];
        int index = start;
        while (index <= end && postorder[index] < base) {
            ++index;
        }
        for (int i = index; i < end; ++i) {
            if (postorder[i] <= base) {
                return false;
            }
        }
        return verifyPostorder(postorder, start, index - 1) && verifyPostorder(postorder, index, end - 1);
    }
};