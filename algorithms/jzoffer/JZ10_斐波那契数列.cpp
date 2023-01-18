//
// Created by lixiaoqing on 2022/3/28.
//

class Solution {
public:
    int Fibonacci(int n) {
        /**
         * 方法1：递归
         */
//        if (n <= 2) {
//            return 1;
//        }
//        return Fibonacci(n - 1) + Fibonacci(n - 2);

        /**
         * 方法2：循环
         */
        if (n <= 2) {
            return 1;
        }
        int num1 = 1, num2 = 1;
        for (int i = 3; i <= n; ++i) {
            num2 += num1;
            num1 = num2 - num1;
        }
        return num2;
    }
};

int main() {
    return 0;
}