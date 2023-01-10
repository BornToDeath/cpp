//
// Created by lixiaoqing on 2023/1/10.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        } else if (b.empty()) {
            return a;
        }
        std::string ans;
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = 0;
            if (i >= 0) {
                sum += a[i] - '0';
                --i;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                --j;
            }
            sum += carry;
            carry = sum / 2;
            sum %= 2;
            ans.push_back(sum + '0');
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    std::cout << Solution().addBinary("1010", "1011") << std::endl;
    return 0;
}