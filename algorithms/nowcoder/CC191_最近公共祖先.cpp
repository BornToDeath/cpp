//
// Created by lixiaoqing on 2022/5/31.
//

#include <iostream>

class LCA {
public:
    int getLCA(int a, int b) {
        /**
         * 方法1：递归
         */
//        if (a == b) {
//            return a;
//        }
//        return a > b ? getLCA(a / 2, b) : getLCA(a, b / 2);

        /**
         * 方法2：迭代
         */
        while (a != b) {
            if (a > b) {
                a /= 2;
            } else {
                b /= 2;
            }
        }
        return a;
    }
};

int main() {
    std::cout << LCA().getLCA(8, 9) << std::endl;
    return 0;
}