//
// Created by lixiaoqing on 2022/3/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return -1;
        }
        if (rotateArray.size() == 1 || rotateArray[0] < rotateArray[rotateArray.size() - 1]) {
            return rotateArray[0];
        }

        int start = 0;
        int end = rotateArray.size() - 1;
        while (start < end) {
//            printf("[%d, %d]\n", start, end);
            // 数组如果是有序的
            if (rotateArray[start] < rotateArray[end]) {
                break;
            }
            int mid = ((end - start) >> 1) + start;
            // 左半部分是有序的（最小数一定在右边，所以需要 mid+1 ）
            if (rotateArray[start] < rotateArray[mid]) {
                start = mid + 1;
            }
            // 右半部分是有序的（此处不能 mid-1, 因为mid有可能是最小值）
            else if (rotateArray[mid] < rotateArray[end]) {
                end = mid;
            }
            // start = mid = end
            else {
                ++start;
            }
        }
//        printf("start=%d\n", start);
        return rotateArray[start];
    }
};

int main() {
//    vector<int> arr = {3, 4, 5, 1, 2};
//    vector<int> arr = {1, 0, 0, 0, 0, 1};
//    vector<int> arr = {5, 1, 2, 3, 4};
//    vector<int> arr = {1, 0, 1, 1, 1};
    vector<int> arr = {1, 1, 1, 0, 1};
    std::cout << Solution().minNumberInRotateArray(arr) << std::endl;
    return 0;
}