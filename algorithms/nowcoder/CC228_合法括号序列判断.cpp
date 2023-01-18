//
// Created by lixiaoqing on 2022/6/8.
//

#include <iostream>
#include <string>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        int count = 0;
        for (auto ch: A) {
            if (ch == '(') {
                ++count;
            } else if (ch == ')'){
                if (count <= 0) {
                    return false;
                }
                --count;
            } else {
                return false;
            }
        }
        return count == 0;
    }
};

int main() {
    std::string str = "()()(((())))";
    std::cout << Parenthesis().chkParenthesis(str, str.length()) << std::endl;
    return 0;
}