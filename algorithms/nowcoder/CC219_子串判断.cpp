//
// Created by lixiaoqing on 2022/6/8.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        std::vector<bool> res(n, false);
        for (int i = 0; i < n; ++i) {
            res[i] = s.find(p[i]) != std::string::npos;
        }
        return res;
    }
};

int main() {
    std::vector<std::string> arr = {"a", "b", "c", "d"};
    std::string str = "abc";
    auto res = Substr().chkSubStr(arr, arr.size(), str);
    return 0;
}