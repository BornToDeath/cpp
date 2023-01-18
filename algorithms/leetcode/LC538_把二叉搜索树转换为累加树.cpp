//
// Created by lixiaoqing on 2022/8/9.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <map>
#include "TreeNode.h"

/**
 * 方法1：使用 map 记录树中节点，然后更新 map 中元素，最后再用 map 更新树
 * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
 */
//class Solution {
//public:
//    TreeNode *convertBST(TreeNode *root) {
//        /**
//         * 方法1：使用 map 记录树中节点，然后更新 map 中元素，最后再用 map 更新树
//         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
//         */
//        // 初始化 map
//        dfsInit(root);
//        // 更新 map
//        int sum = 0;
//        for (auto &ele: map) {
//            map[ele.first] += sum;
//            sum = map[ele.first];
//        }
//        // 用 map 更新树
//        dfsUpdate(root);
//        return root;
//    }
//
//private:
//    void dfs(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//        if (root->right) {
//            dfs(root->right);
//            root->val += root->right->val;
//        }
//        dfs(root->left);
//        root->val += root
//    }
//
//    void dfsInit(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//        map[root->val] = root->val;
//        dfsInit(root->left);
//        dfsInit(root->right);
//    }
//
//    void dfsUpdate(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//        root->val = map[root->val];
//        dfsUpdate(root->left);
//        dfsUpdate(root->right);
//    }
//
//private:
//    std::map<int, int, std::greater<int>> map;
//};

/**
 * 方法2：利用二叉搜索树的性质，先遍历右子树、再根、再左子树
 * 时间复杂度 O(n) ，空间复杂度 O(n)（包括递归栈开销）
 */
//class Solution {
//public:
//    TreeNode *convertBST(TreeNode *root) {
//        /**
//         * 方法2.1
//         */
////        auto last = new TreeNode(0);
////        dfs(root, last);
////        return root;
//
//        /**
//         * 方法2.2：在方法2.1的基础上进行优化
//         */
//        if (root == nullptr) {
//            return nullptr;
//        }
//        convertBST(root->right);
//        sum += root->val;
//        root->val = sum;
//        convertBST(root->left);
//        return root;
//    }
//
//private:
//    void dfs(TreeNode *root, TreeNode *last) {
//        if (root == nullptr) {
//            return;
//        }
//        dfs(root->right, last);
//        root->val += last->val;
//        last->val = root->val;
//        dfs(root->left, last);
//    }
//
//private:
//    int sum{0};
//};

/**
 * 方法3：Morris 遍历
 * 时间复杂度 O(n) ，空间复杂度 O(1)
 * 参考：
 * 1. https://leetcode.cn/problems/convert-bst-to-greater-tree/solution/ba-er-cha-sou-suo-shu-zhuan-huan-wei-lei-jia-sh-14/
 * 2. https://juejin.cn/post/7021341254457753631
 */
class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        auto node = root;
        while (node) {
            // 如果当前节点有右孩子
            if (node->right) {
                // 找到右子树上的最左节点
                auto leftest = getLeftestNode(node);
                if (leftest->left) {  // 第二次访问
                    // 重置左孩子指针
                    leftest->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                } else {  // 第一次访问
                    leftest->left = node;
                    node = node->right;
                }
            } else {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
        }
        return root;
    }

private:
    // 找最左结点
    TreeNode *getLeftestNode(TreeNode *node) {
        TreeNode *succ = node->right;
        // left 指针可能还没被修改（说明是第一次访问），也可能已经被修改了（说明是第二次访问）
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }
};

void print(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    printf("%d, ", root->val);
    print(root->left);
    print(root->right);
}

int main() {
    auto root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    auto ans = Solution().convertBST(root);
    print(ans);
    return 0;
}