//
// Created by lixiaoqing on 2022/6/7.
//

#include <vector>

using namespace std;

class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        for (int i = n; i > 0; i >>= 1) {
            if (A[i] == i) {
                return true;
            }
        }
        return A[0] == 0;
    }
};