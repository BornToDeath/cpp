//
// Created by lixiaoqing on 2022/9/29.
//

#include <iostream>
#include <vector>

using namespace std;


template<typename T>
void print(const std::vector<T> &data) {
    for (auto e: data) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int InversePairs(vector<int> &data) {
        /**
         * 方法：归并排序的思想
         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
        merge_sort(data, 0, data.size() - 1);
        return count % 1000000007;
    }

private:
    void merge_sort(std::vector<int> &data, int start, int end) {
        if (start >= end) {
            return;
        }
        auto mid = ((end - start) >> 1) + start;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        std::vector<int> temp(end - start + 1);
        int i = start, j = mid + 1, k = 0;
        while (i <= mid && j <= end) {
            if (data[i] > data[j]) {
                temp[k++] = data[i++];
                count += end - j + 1;
            } else {
                temp[k++] = data[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = data[i++];
        }
        while (j <= end) {
            temp[k++] = data[j++];
        }
        std::copy(temp.begin(), temp.end(), data.begin() + start);
    }

private:
    long count{0};
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    std::cout << Solution().InversePairs(data) << std::endl;
    print(data);
    return 0;
}