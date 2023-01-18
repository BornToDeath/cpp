//
// Created by lixiaoqing on 2022/8/25.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> ans(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                ans[i - 1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                ans[i - 1] = "Fizz";
            } else if (i % 5 == 0) {
                ans[i - 1] = "Buzz";
            } else {
                ans[i - 1] = std::to_string(i);
            }
        }
        return ans;
    }
};