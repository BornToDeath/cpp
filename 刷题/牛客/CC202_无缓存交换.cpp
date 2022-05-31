//
// Created by lixiaoqing on 2022/5/31.
//

#include <vector>

using namespace std;

class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        /**
         * 方法1：加法运算
         */
//        AB[0] += AB[1];
//        AB[1] = AB[0] - AB[1];
//        AB[0] -= AB[1];
//        return AB;

        /**
         * 方法2：异或运算
         */
        AB[0] ^= AB[1];
        AB[1] ^= AB[0];
        AB[0] ^= AB[1];
        return AB;
    }
};