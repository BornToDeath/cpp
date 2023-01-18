//
// Created by lixiaoqing on 2022/7/19.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

/**
 * 方法1：直接遍历。时间复杂度 O(n^2) ，空间复杂度 O(n) ，其中 n 表示日程安排的数量
 */
//class MyCalendarTwo {
//public:
//    MyCalendarTwo() {
//
//    }
//    bool book(int start, int end) {
//
//        for (auto &pair: overlaps) {
//            if (start < pair.second && end > pair.first) {
//                return false;
//            }
//        }
//        for (auto &pair : booked) {
//            if (start < pair.second && end > pair.first) {
//                overlaps.emplace_back(std::max(start, pair.first), std::min(end, pair.second));
//            }
//        }
//        booked.emplace_back(start, end);
//        return true;
//    }
//
//private:
//    // 已经预定的区间
//    std::vector<std::pair<int, int>> booked;
//    // 已经预定过两次的区间
//    std::vector<std::pair<int, int>> overlaps;
//};

/**
 * 方法2：差分数组
 */
//class MyCalendarTwo {
//public:
//    MyCalendarTwo() {
//
//    }
//
//    bool book(int start, int end) {
//        int maxBook = 0;
//        ++cnt[start];
//        --cnt[end];
//        for (auto &pair : cnt) {
//            maxBook += pair.second;
//            if (maxBook > 2) {
//                --cnt[start];
//                ++cnt[end];
//                return false;
//            }
//        }
//        return true;
//    }
//
//private:
//    // 查分数组必须用有序的map
//    std::map<int, int> cnt;
//};

/**
 * 方法3：线段树（官方解法）
 */
//class MyCalendarTwo {
//public:
//    MyCalendarTwo() {
//
//    }
//
//    void update(int start, int end, int val, int l, int r, int idx) {
//        if (r < start || end < l) {
//            return;
//        }
//        if (start <= l && r <= end) {
//            tree[idx].first += val;
//            tree[idx].second += val;
//        } else {
//            int mid = (l + r) >> 1;
//            update(start, end, val, l, mid, 2 * idx);
//            update(start, end, val, mid + 1, r, 2 * idx + 1);
//            tree[idx].first = tree[idx].second + std::max(tree[2 * idx].first, tree[2 * idx + 1].first);
//        }
//    }
//
//    bool book(int start, int end) {
//        update(start, end - 1, 1, 0, 1e9, 1);
//        if (tree[1].first > 2) {
//            update(start, end - 1, -1, 0, 1e9, 1);
//            return false;
//        }
//        return true;
//    }
//
//private:
//    // <idx, <first, second>>: idx 表示节点索引，first 表示该区间最大值，second 是该区间懒标记
//    std::unordered_map<int, std::pair<int, int>> tree;
};


/**
 * 方法4：线段树（容易理解的解法），计算区间最大值。
 */
class MyCalendarTwo {

private:

    // 线段树节点数据结构
    class Node {
    public:
        Node *left{nullptr};   // 左孩子节点
        Node *right{nullptr};  // 右孩子节点
        int max{0};            // 记录区间最大值
        int lazy{0};           // 懒惰标记
    };

public:

    MyCalendarTwo() : root(new Node()) {

    }

    bool book(int start, int end) {
        if (query(root, 0, N, start, end - 1) >= 2) {
            return false;
        }
        update(root, 0, N, start, end - 1, 1);
        return true;
    }

private:

    // 查询区间 [l, r] 的最大值
    int query(Node *node, int start, int end, int l, int r) {
        if (r < start || l > end) {  // 区间没有交集
            return 0;
        } else if (l <= start && r >= end) {  // 当前区间包含在目标区间中
            return node->max;
        } else {
            // 计算左右部分区间的最大值
            auto mid = (end - start) / 2 + start;
            pushDown(node, mid - start + 1, end - mid);
            return std::max(query(node->left, start, mid, l, r), query(node->right, mid + 1, end, l, r));
        }
    }

    // 线段树更新
    void update(Node *node, int start, int end, int l, int r, int val) {
        if (r < start || l > end) {  // 区间没有交集
            return;
        } else if (l <= start && r >= end) {  // 当前区间包含在目标区间中
            node->max += val;
            node->lazy += val;
            return;
        } else {
            // 更新左右部分
            auto mid = (end - start) / 2 + start;
            pushDown(node, mid - start + 1, end - mid);
            update(node->left, start, mid, l, r, val);
            update(node->right, mid + 1, end, l, r, val);
            pushUp(node);
        }
    }

    // 向下更新懒惰标记
    void pushDown(Node *node, int leftNum, int rightNum) {
        if (node->left == nullptr) {
            node->left = new Node();
        }
        if (node->right == nullptr) {
            node->right = new Node();
        }
        if (node->lazy == 0) {
            return;
        }
        // 更新左右孩子的最大值
        node->left->max += node->lazy;
        node->right->max += node->lazy;
        // 向下传递懒惰值
        node->left->lazy += node->lazy;
        node->right->lazy += node->lazy;
        // 更新之后将当前懒惰值置为0
        node->lazy = 0;
    }

    // 向上更新区间最大值
    void pushUp(Node *node) {
        node->max = std::max(node->left->max, node->right->max);
    }

private:
    Node *root{nullptr};
    const int N = 1e9;
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main() {

    MyCalendarTwo calendar;
    std::cout << std::boolalpha;
    std::cout << calendar.book(10, 20) << std::endl;
    std::cout << calendar.book(50, 60) << std::endl;
    std::cout << calendar.book(10, 40) << std::endl;
    std::cout << calendar.book(5, 15) << std::endl;
    std::cout << calendar.book(5, 10) << std::endl;
    std::cout << calendar.book(25, 55) << std::endl;
    return 0;
}