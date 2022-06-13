//
// Created by lixiaoqing on 2022/6/13.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        /**
         * 方法1：递归
         */
        std::map<int, UndirectedGraphNode*> visitedNodes;
        return clone(node, visitedNodes);
    }

private:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, std::map<int, UndirectedGraphNode *> &visitedNodes) {
        if (node == nullptr) {
            return nullptr;
        }
        if (visitedNodes.find(node->label) != visitedNodes.end()) {
            return visitedNodes[node->label];
        }
        auto newNode = new UndirectedGraphNode(node->label);
        visitedNodes[node->label] = newNode;
        for (auto &ele: node->neighbors) {
            auto temp = clone(ele, visitedNodes);
            newNode->neighbors.push_back(temp);
        }
        return newNode;
    }
};