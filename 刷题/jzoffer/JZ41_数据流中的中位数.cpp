//
// Created by lixiaoqing on 2022/4/6.
//

#include <vector>
#include <set>
#include <iostream>

/**
 * 方法1：使用 std::vector + std::sort
 */
class Solution {
public:
    void Insert(int num) {
        arr.emplace_back(num);
        std::sort(arr.begin(), arr.end());
    }

    double GetMedian() {
        if (arr.empty()) {
            return 0;
        }
        if (arr.size() % 2 == 1) {
            return arr[arr.size() / 2];
        } else {
            auto mid = arr.size() / 2;
            return static_cast<double>(arr[mid - 1] + arr[mid]) / 2;
        }
    }

private:
    std::vector<int> arr;
};

/**
 * 方法2：使用 std::multiset
 */
//class Solution {
//public:
//    void Insert(int num) {
//        _set.insert(num);
//    }
//
//    double GetMedian() {
//        if (_set.empty()) {
//            return 0;
//        }
//        auto it1 = _set.begin();
//        auto it2 = it1;
//        std::advance(it1, _set.size() / 2);
//        std::advance(it2, _set.size() / 2 - !(_set.size() % 2));
//        return (*it1 + *it2) / 2.0;
//    }
//
//private:
//    std::multiset<int> _set;
//};

int main() {
    std::cout << (10 % 2) << std::endl;
    std::cout << !(10 % 2) << std::endl;
    std::cout << (9 % 2) << std::endl;
    std::cout << !(9 % 2) << std::endl;
    return 0;
}