//
// Created by lixiaoqing on 2022/6/7.
//

#include <string>

using namespace std;

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        return (s1 + s1).find(s2) != std::string::npos;
    }
};