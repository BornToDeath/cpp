//
// Created by lixiaoqing on 2022/3/29.
//

class Solution {
public:
    int rectCover(int number) {
        /**
         * 方法1：递归
         */
//        if (number <= 2) {
//            return number;
//        }
//        return rectCover(number - 1) + rectCover(number - 2);

        /**
         * 方法2：循环
         */
        if (number <= 0) {
            return 0;
        }
        int num1 = 0;
        int num2 = 1;
        for (int i = 0; i < number; ++i) {
            num2 += num1;
            num1 = num2 - num1;
        }
        return num2;
    }
};

int main() {

    return 0;
}