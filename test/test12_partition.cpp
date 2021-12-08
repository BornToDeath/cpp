//
// Created by lixiaoqing on 2021/12/7.
//

#include <iostream>
#include <vector>
#include <forward_list>

/**
 * 快速排序
 * @tparam ForwardIt
 * @param first
 * @param last
 */
template<typename ForwardIt>
void quickSort(ForwardIt first, ForwardIt last) {
    if (first == last) {
        return;
    }
    auto pivot = *std::next(first, std::distance(first, last) / 2);
    /* 注意: C++14 及以上才支持泛型 lambda (在参数列表中使用auto) */
    // 1. 将小于 pivot 的元素至于前段
    ForwardIt middle1 = std::partition(first, last, [pivot](const auto &em) { return em < pivot; });
    // 2. 将 pivot 置于交界处
    ForwardIt middle2 = std::partition(middle1, last, [pivot](const auto &em) { return em <= pivot; });
    quickSort(first, middle1);
    quickSort(middle2, last);
}

void test01() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Original vector:\n    ";
    for (auto elem: v) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;

    auto it = std::partition(v.begin(), v.end(), [](int elem) { return elem % 2 == 0; });
    std::cout << "Partitioned vector:\n    ";
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << " * ";
    std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::forward_list<int> fl = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    std::cout << "Unsorted list:\n    ";
    std::for_each(fl.begin(), fl.end(), [](int elem) { std::cout << elem << ", "; });
    std::cout << std::endl;

    quickSort(std::begin(fl), std::end(fl));
    std::cout << "Sorted list:\n    ";
    std::for_each(fl.begin(), fl.end(), [](int elem) { std::cout << elem << ", "; });
    std::cout << std::endl;
}

int main() {
    test01();
    return 0;
}