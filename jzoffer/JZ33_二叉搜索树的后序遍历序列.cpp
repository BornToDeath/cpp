//
// Created by lixiaoqing on 2022/3/6.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }
        return verify(sequence, 0, sequence.size() - 1);
    }

private:
    bool verify(const vector<int> &sequence, int start, int end) {
        if (start >= end || start < 0 || end > sequence.size()) {
            return true;
        }
        const int value = sequence[end];
        int index = start;
        while (index < end) {
            if (sequence[index] >= value) {
                break;
            }
            ++index;
        }
        for (int i = index; i < end; ++i) {
            if (sequence[i] <= value) {
                return false;
            }
        }
        return verify(sequence, start, index - 1) && verify(sequence, index, end-1);
    }
};

int main() {
    std::cout << std::boolalpha;
    Solution solution;
    vector<int> sequence = {1,3,2};
    std::cout << solution.VerifySquenceOfBST(sequence) << std::endl;
    return 0;
}