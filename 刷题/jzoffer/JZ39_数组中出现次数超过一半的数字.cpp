//
// Created by lixiaoqing on 2022/4/11.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        /**
         * 方法1：利用map，时间复杂度 O(n)，空间复杂度 O(n)
         */
//        std::map<int, int> dp;
//        for (auto num: numbers) {
//            dp[num]++;
//            if (dp[num] > numbers.size() / 2) {
//                return num;
//            }
//        }
//        return -1;

        /**
         * 方法2：sort。时间复杂度就是快排的时间复杂度 O(nlogn)
         */
//        std::sort(numbers.begin(), numbers.end());
//        return numbers[numbers.size() / 2];

        /**
         * 方法3：时间复杂度 O(n)，空间复杂度 O(1)
         * 两个数相同则+1，不同则-1，最后剩下来的那个数就是超过一半的数字
         */
        int ele = -1;
        int count = 0;
        for (auto num: numbers) {
            if (count == 0) {
                ++count;
                ele = num;
            } else {
                num == ele ? ++count : --count;
            }
        }
        return ele;
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    std::cout << Solution().MoreThanHalfNum_Solution(arr) << std::endl;
}
