//
// Created by lixiaoqing on 2022/3/2.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

void printArray(const std::vector<int> nums) {
    for(const auto& num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    vector<vector<int> > Print(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return {};
        }

        std::vector<std::vector<int>> numsVec;
        left2RightStack.push(pRoot);
        while (!(left2RightStack.empty() && right2LeftStack.empty())) {
            std::vector<int> nums;
            if (!left2RightStack.empty()) {
                while (!left2RightStack.empty()) {
                    auto node = left2RightStack.top();
                    left2RightStack.pop();
                    nums.emplace_back(node->val);
                    if (node->left != nullptr) {
                        right2LeftStack.push(node->left);
                    }
                    if (node->right != nullptr) {
                        right2LeftStack.push(node->right);
                    }
                }
            } else {
                while (!right2LeftStack.empty()) {
                    auto node = right2LeftStack.top();
                    right2LeftStack.pop();
                    nums.emplace_back(node->val);
                    if (node->right != nullptr) {
                        left2RightStack.push(node->right);
                    }
                    if (node->left != nullptr) {
                        left2RightStack.push(node->left);
                    }
                }
            }
            numsVec.emplace_back(nums);
        }
        return numsVec;
    }

private:
    std::stack<TreeNode*> left2RightStack;
    std::stack<TreeNode*> right2LeftStack;
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    solution.Print(root);
    return 0;
}