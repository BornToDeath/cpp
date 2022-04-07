//
// Created by lixiaoqing on 2022/4/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        /**
         * 方法1：暴力解法。时间复杂度超限
         */
//        int sum = 0;
//        for (int i = 0; i < data.size(); ++i) {
//            for (int j = i + 1; j < data.size(); ++j) {
//                if (data[i] > data[j]) {
//                    ++sum;
//                    sum %= 1000000007;
//                }
//            }
//        }
//        return sum;

        /**
         * 方法2：借助归并排序。时间复杂度 O(nlogn)
         */
        mergeSort(data, 0, data.size() - 1);
        return count;
    }

private:
    void mergeSort(vector<int> &data, const int left, const int right) {
        if (left >= right) {
            return;
        }
        auto mid = left + ((right - left) >> 1);
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }

    void merge(vector<int> &data, const int left, const int mid, const int right) {
        auto i = left;
        auto j = mid + 1;
        vector<int> temp(right - left + 1, 0);
        auto loc = 0;
        while (i <= mid && j <= right) {
            if (data[i] > data[j]) {
                // 记录逆序队的个数：即前半部分有序数组的部分长度(mid-i+1)
                count += mid - i + 1;
                count %= K;
                temp[loc++] = data[j++];
            } else {
                temp[loc++] = data[i++];
            }
        }
        while (i <= mid) {
            temp[loc++] = data[i++];
        }
        while (j <= right) {
            temp[loc++] = data[j++];
        }
        std::copy(temp.begin(), temp.end(), data.begin() + left);
    }

private:
    // 记录逆序队的个数
    int count = 0;
    const int K = 1000000007;
};

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
//    vector<int> data = {1, 2, 3};
    cout << Solution().InversePairs(data) << endl;
    return 0;
}