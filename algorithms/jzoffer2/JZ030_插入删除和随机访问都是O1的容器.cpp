//
// Created by lixiaoqing on 2023/4/25.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

/*
 * 要想 insert, remove, getRandom 都是 O(1) 的时间复杂度, 考虑用「数组 + 哈希表」的方式来实现，数组存放元素，哈希表存放元素及在数组中的下标
 */
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        std::srand(time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (umap.count(val)) {
            return false;
        }
        nums.push_back(val);
        umap.insert({val, nums.size() - 1});
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (umap.count(val) == 0) {
            return false;
        }
        nums[umap[val]] = nums.back();
        umap[nums.back()] = umap[val];
        nums.pop_back();
        umap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int pos = std::rand() % nums.size();
        return nums.at(pos);
    }

private:
    std::vector<int> nums;
    std::unordered_map<int, int> umap;
};

int main() {
    RandomizedSet set;
//    std::vector<int> nums = {1, 2, 3, 4, 5, 1, 1, 1, 2, 3, 1, 3, 4, 5};
//    for (auto n: nums) {
//        std::cout << set.insert(n) << ", "
//                  << set.getRandom() << std::endl;
//    }

    set.insert(0);
    set.insert(1);
    set.remove(0);
    set.insert(2);
    set.remove(1);
    std::cout << set.getRandom() << std::endl;

    return 0;
}