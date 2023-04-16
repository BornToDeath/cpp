//
// Created by lixiaoqing on 2023/4/13.
//


/*
 * 方法1: 数组, 不 AC , 时间超限
 * 时间复杂度 O(n^2 * logn) , 空间复杂度 O(n)
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        nums.emplace_back(num);
        std::sort(nums.begin(), nums.end());
    }

    double findMedian() {
        if (nums.empty()) {
            return -1;
        }
        const int size = nums.size();
        if (size % 2) {
            return nums[size / 2];
        } else {
            return (nums[size / 2] + nums[size / 2 - 1]) * 1.0 / 2;
        }
    }

private:
    std::vector<int> nums;
};

/*
 * 方法2: 优先队列 + 双指针
 * 时间复杂度 O(logn) , 空间复杂度 O(n)
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        mset.insert(num);
    }

    double findMedian() {
        if (mset.empty()) {
            return -1;
        }
        const int size = mset.size();
        auto it = mset.begin();
        std::advance(it, size / 2);
        if (size % 2) {
            return *it;
        } else {
            auto sum = *it;
            std::advance(it, -1);
            return (sum + *it) * 1.0 / 2;
        }
    }

private:
    std::multiset<int> mset;
};