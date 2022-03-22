//
// Created by lixiaoqing on 2022/3/22.
//

/**
 * 结论：std::unique() 会移除容器中相邻的重复元素（只保留一个），然后返回最后一个不重复元素的下一个位置。
 * 对于无序的容器，该方法不会删除前后不相邻的重复元素。所以如果想要实现删除容器中所有重复的元素的话，
 * 需要先对容器进行排序，然后再应用此方法。
 */

#include <iostream>
#include <vector>
#include <algorithm>

template<class Type>
void printArray(const std::vector<Type> &arr) {
    std::cout << "================" << std::endl;
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

void test01() {
    std::vector<int> v = {1, 2, 4, 5, 6, 6, 4, 1, 1, 4, 4, 8};
    printArray(v);

    // 由于数组是未排序的，所以只会将相邻重复元素组中的除第一个元素之外的其他元素移到容器后面
    auto last = std::unique(v.begin(), v.end());
    printArray(v);
    std::cout << last - v.begin() << std::endl;
//    v.erase(last, v.end());
//    printArray(v);

    // 排序
    std::sort(v.begin(), v.end());
    printArray(v);

    // 此时由于数组是排序的，所以会将所有重复出现的元素移到容器后面，使得容器前面部分是不重复的
    last = std::unique(v.begin(), v.end());
    printArray(v);
    std::cout << last - v.begin() << std::endl;

    // 此时删除重复元素，使得整个容器是不重复的
    v.erase(last, v.end());
    printArray(v);
}

void test02() {
    // a vector containing several duplicate elements
    std::vector<int> v{1, 2, 1, 1, 3, 3, 3, 4, 5, 4};
    auto print = [&](int id) {
        std::cout << "@" << id << ": ";
        for (int i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    };
    print(1);

    // remove consecutive (adjacent) duplicates
    auto last = std::unique(v.begin(), v.end());
    print(11);
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(2);

    // sort followed by unique, to remove all duplicates
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    print(3);

    last = std::unique(v.begin(), v.end());
    // v now holds {1 2 3 4 5 x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(4);
}

int main() {
    test01();
    return 0;
}