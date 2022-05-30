//
// Created by lixiaoqing on 2022/5/30.
//

#include <iostream>

class Transform {
public:
    int calcCost(int A, int B) {
        /**
         * 方法1：
         */
//        int count = 0;
//        A ^= B;
//        while (A) {
//            if ((A & 1) == 1) {
//                ++count;
//            }
//            A >>= 1;
//        }
//        return count;

        /**
         * 方法2：
         */
        int count = 0;
        A ^= B;
        while (A) {
            ++count;
            A &= A - 1;
        }
        return count;
    }
};

int main() {
    std::cout << Transform().calcCost(10, 5) << std::endl;
    return 0;
}