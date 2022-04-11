//
// Created by lixiaoqing on 2022/4/11.
//

#include <iostream>
#include <vector>

using namespace std;

inline void printArray(const std::vector<int> &array) {
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, ", "));
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
    vector<int> reOrderArrayTwo(vector<int> &array) {
        // 判断是否是偶数
        auto isEven = [](int num) -> bool {
            return num % 2 == 0;
        };
        int left = 0;
        int right = array.size() - 1;
        while (left < right) {
            while (left < right && !isEven(array[left])) {
                ++left;
            }
            while (left < right && isEven(array[right])) {
                --right;
            }
            if (left < right) {
                auto temp = array[left];
                array[left] = array[right];
                array[right] = temp;
                ++left;
                --right;
            }
        }
        return array;
    }
};

int main() {
    std::vector<int> array = {1, 2, 3, 5, 6, 7, 10, 3, 2, 5, 5, 6, 4, 3, 32};
    printArray(array);
    auto res = Solution().reOrderArrayTwo(array);
    printArray(res);
    return 0;
}