//
// Created by lixiaoqing on 2022/6/7.
//

#include <vector>

using namespace std;

class Finder {
public:
    int findMissing(vector<vector<int> > numbers, int n) {
        for (int i = 0; i < n; ++i) {
            if (numbers[i][0] != (i & 1)) {
                return i;
            }
        }
        return n;
    }
};