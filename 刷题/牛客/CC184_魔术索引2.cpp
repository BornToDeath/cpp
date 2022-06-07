//
// Created by lixiaoqing on 2022/6/7.
//

#include <vector>

using namespace std;

class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        for (int i = 0; i < n;) {
            if (A[i] == i) {
                return true;
            } else if (A[i] < i) {
                ++i;
            } else {
                i = A[i];
            }
        }
        return false;
    }
};