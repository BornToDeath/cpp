//
// Created by lixiaoqing on 2022/4/25.
//

#include <iostream>
#include <vector>

using namespace std;

inline void printArray(const std::vector<int> &array) {
    std::for_each(array.begin(), array.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int> &array) {
        /**
         * 方法1：时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        std::vector<int> evens;
//        int oddPos = 0;
//        for (auto num: array) {
//            if (num % 2 == 1) {
//                array[oddPos++] = num;
//            } else {
//                evens.emplace_back(num);
//            }
//        }
//        if (!evens.empty()) {
//            for (auto num : evens) {
//                array[oddPos++] = num;
//            }
//        }
//        return array;

        /**
         * 方法2：时间复杂度 O(n^2) ，空间复杂度 O(1)
         */
        // 判断是否是偶数
        auto isEven = [](int num) -> bool { return num % 2 == 0; };
        // 交换
        auto swap = [&array](int i, int j) {
            auto temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        };
        for (int index = 1; index < array.size(); ++index) {
            if (!isEven(array[index]) && isEven(array[index - 1])) {
                int pos = index;
                while (pos > 0 && !isEven(array[pos]) && isEven(array[pos - 1])) {
                    swap(pos, pos - 1);
                    --pos;
                }
            }
        }
        return array;
    }
};

int main() {
    std::vector<int> array = {1, 3, 5, 6, 7};
    printArray(array);
    Solution().reOrderArray(array);
    printArray(array);
    return 0;
}