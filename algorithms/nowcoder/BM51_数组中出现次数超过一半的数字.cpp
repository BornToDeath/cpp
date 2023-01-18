//
// Created by lixiaoqing on 2022/10/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        /**
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int num, count = 0;
        for (auto e: numbers) {
            if (count == 0) {
                num = e;
                count = 1;
            } else {
                e == num ? ++count : --count;
            }
        }
        return num;
    }
};

int main() {
    std::vector<int> v = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    std::cout << Solution().MoreThanHalfNum_Solution(v) << std::endl;
    return 0;
}