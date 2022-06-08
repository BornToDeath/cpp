//
// Created by lixiaoqing on 2022/6/7.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class AntiOrder {
public:
    int count(vector<int> A, int n) {
        /**
         * 方法1：借助 map
         */
//        std::map<int, int, std::greater<int>> _map;
//        int count = 0;
//        for (auto ele: A) {
//            if (!_map.empty() && _map.begin()->first > ele) {
//                for (auto &pair: _map) {
//                    if (pair.first > ele) {
//                        count += pair.second;
//                    }
//                }
//            }
//            _map[ele]++;
//        }
//        return count;

        /**
         * 方法2：for 双重遍历
         */
//        int count = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                if (A[i] > A[j]) {
////                    printf("%d, %d\n", A[i], A[j]);
//                    ++count;
//                }
//            }
//        }
//        return count;

        /**
         * 方法3：借助归并排序
         */
        mergeSort(A, 0, n - 1);
        return cnt;
    }

private:
    void mergeSort(std::vector<int> &arr, int start, int end) {
        if (start >= end) {
            return;
        }
        auto mid = (end - start) / 2 + start;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        std::vector<int> temp;
        int i = start, j = mid + 1;
        while (i <= mid && j <= end) {
            if (arr[i] > arr[j]) {
//                printf("%d, %d\n", arr[i], arr[j]);
                cnt += end - j + 1;
                temp.emplace_back(arr[i++]);
            } else {
                temp.emplace_back(arr[j++]);
            }
        }
        while (i <= mid) {
            temp.emplace_back(arr[i++]);
        }
        while (j <= end) {
            temp.emplace_back(arr[j++]);
        }
        std::copy(temp.begin(), temp.end(), arr.begin() + start);
    }

private:
    int cnt = 0;
};

int main() {
    std::vector<int> arr = {6, 5, 4, 3, 4, 5, 4, 1};
    std::cout << AntiOrder().count(arr, arr.size()) << std::endl;
    return 0;
}