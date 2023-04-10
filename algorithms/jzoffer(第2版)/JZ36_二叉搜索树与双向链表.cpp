//
// Created by lixiaoqing on 2023/3/17.
//

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

void print(Node *head) {
    while (head) {
        std::cout << head->val << ", ";
        head = head->right;
    }
    std::cout << std::endl;
}

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        /**
         * 时间复杂度 O(n) ，最坏情况下空间复杂度 O(n)
         */
        auto head = dfs(root);
        if (head) {
            head->left = tail;
        }
        if (tail) {
            tail->right = head;
        }
        return head;
    }

private:
    Node *dfs(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto head = dfs(root->left);
        if (head == nullptr) {
            head = root;
        }
        root->left = tail;
        if (tail) {
            tail->right = root;
        }
        tail = root;
        dfs(root->right);
        return head;
    }

private:
    Node *tail{nullptr};
};

int main() {
    auto root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    auto head = Solution().treeToDoublyList(root);
    print(head);
    return 0;
}