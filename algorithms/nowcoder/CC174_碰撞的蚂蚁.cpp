//
// Created by lixiaoqing on 2022/5/30.
//

#include <iostream>

class Ants {
public:
    double antsCollision(int n) {
        return 1 - (1.0 / (1 << (n - 1)));
    }
};

int main() {
    std::cout << Ants().antsCollision(3) << std::endl;
    return 0;
}