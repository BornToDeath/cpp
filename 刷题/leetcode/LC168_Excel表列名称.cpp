//
// Created by lixiaoqing on 2023/1/16.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        std::string ans;
        while (columnNumber) {
            columnNumber -= 1;  // 这是最关键的！
            ans.insert(ans.begin(), columnNumber % 26 + 'A');
            columnNumber /= 26;
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().convertToTitle(1) << std::endl;
    std::cout << Solution().convertToTitle(26) << std::endl;
    std::cout << Solution().convertToTitle(27) << std::endl;
    std::cout << Solution().convertToTitle(28) << std::endl;
    std::cout << Solution().convertToTitle(52) << std::endl;
    std::cout << Solution().convertToTitle(701) << std::endl;
    std::cout << Solution().convertToTitle(2147483647) << std::endl;
    return 0;
}