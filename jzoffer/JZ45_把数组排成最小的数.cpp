//
// Created by lixiaoqing on 2022/4/18.
//
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

/**
 * 方法1：全排列，然后取最小值。时间复杂度超限
 */
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty()) {
            return "";
        }
        getString(numbers, 0);
        return minStr;
    }

private:
    /**
     * 全排列
     * @param numbers
     * @param pos
     */
    void getString(vector<int> &numbers, int pos) {
        if (pos == numbers.size()) {
            // 拼接字符串
            auto tempStr = std::accumulate(numbers.begin(), numbers.end(), std::string(""),
                                           [](const std::string &base, int num) { return base + std::to_string(num); });
            if (minStr.empty()) {
                minStr = tempStr;
            } else if (tempStr < minStr) {
                minStr = tempStr;
            }
            return;
        }
        for (int i = pos; i < numbers.size(); ++i) {
            swap(numbers, i, pos);
            getString(numbers, pos + 1);
            swap(numbers, i, pos);
        }
    }

    void swap(vector<int> &numbers, int i, int j) {
        auto temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

private:
    // 记录最小字符串
    std::string minStr;
};

template<typename T>
void printArray(const std::vector<T> &arr) {
    std::for_each(arr.begin(), arr.end(), [](const T ele) { std::cout << ele << ", "; });
    std::cout << std::endl;
}

/**
 * 方法2：利用 std::sort, 关键是制定排序规则。AC
 */
class Solution2 {
public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty()) {
            return "";
        }

        // 转为字符串
        vector<std::string> strs(numbers.size());
        std::transform(numbers.begin(), numbers.end(), strs.begin(), [](int num) { return std::to_string(num); });

        // 按照最小数排列
        std::sort(strs.begin(), strs.end(), [](const std::string &str1, const std::string &str2) {
            // 制定排序规则，这是关键
            return (str1 + str2) < (str2 + str1);
        });

        // 拼接为一个字符串
        auto res = std::accumulate(strs.begin(), strs.end(), std::string(""),
                                   [](const std::string &base, const std::string &str) {
                                       return base + str;
                                   });
        return res;
    }
};

int main() {
    vector<int> numbers = {1, 1220, 122, 1222, 12, 1222, 120, 10};
    auto res = Solution2().PrintMinNumber(numbers);
    std::cout << res << std::endl;
    return 0;
}