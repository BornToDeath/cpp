//
// Created by lixiaoqing on 2022/6/27.
//

#include <iostream>
#include <map>

int main() {

    std::map<int, int, std::greater<int>> map;
    map[1] = 1;
    map[2] = 2;
    map[3] = 3;

//    for (auto &ele: map) {
//        std::cout << ele.first << ", " << ele.second << std::endl;
//    }

    auto it = map.begin();
    std::cout << it->first << ", " << it->second << std::endl;

    return 0;
}