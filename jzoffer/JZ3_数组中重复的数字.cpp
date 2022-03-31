//
// Created by lixiaoqing on 2022/3/31.
//

#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int duplicate(vector<int> &numbers) {
        if (numbers.empty()) {
            return -1;
        }
        std::bitset<10000> bs;
        for (const auto num: numbers) {
            if (bs[num]) {
                return num;
            }
            bs[num] = true;
        }
        return -1;
    }
};