//
// Created by lixiaoqing on 2023/2/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        /**
         * 时间复杂度 O(sqrt(area)) ，空间复杂度 O(1)
         */
        int w = sqrt(area);
        while (area % w != 0) {
            --w;
        }
        return {area / w, w};
    }
};

int main() {
    auto ans = Solution().constructRectangle(122122);
    std::cout << ans[0] << ", " << ans[1] << std::endl;
    return 0;
}