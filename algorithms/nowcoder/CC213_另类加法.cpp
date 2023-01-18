//
// Created by lixiaoqing on 2022/5/31.
//

#include <iostream>

class UnusualAdd {
public:
    int addAB(int A, int B) {
        while (B) {
            int C = (A & B) << 1;
            A ^= B;
            B = C;
        }
        return A;
    }
};

int main() {
    std::cout << UnusualAdd().addAB(1, 9) << std::endl;
    return 0;
}