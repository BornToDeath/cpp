//
// Created by lixiaoqing on 2022/5/30.
//

#include <iostream>

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        return n | (m << j);
    }
};

int main() {
    std::cout << BinInsert().binInsert(1024, 19, 2, 6) << std::endl;
    return 0;
}