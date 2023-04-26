//
// Created by lixiaoqing on 2023/4/25.
//

#include <unordered_map>
#include <deque>
#include <list>
#include <iostream>

class Node {
public:
    Node(int key, int val) : key(key), value(val) {}

    ~Node() {
        next = pre = nullptr;
    }

public:
    int key{};
    int value{};
    Node *next{nullptr};
    Node *pre{nullptr};
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {

    }

    int get(int key) {
        if (umap.count(key) == 0) {
            return -1;
        }
        auto node = umap.at(key);
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        Node *node = nullptr;
        if (umap.count(key)) {
            umap[key]->value = value;
            node = umap.at(key);
            moveToHead(node);
            return;
        }
        node = new Node(key, value);
        umap.insert({key, node});
        node->next = head;
        if (head) {
            head->pre = node;
        }
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
        if (umap.size() > capacity) {
            umap.erase(tail->key);
            auto pre = tail->pre;
            tail->pre = nullptr;
            if (pre) {
                pre->next = nullptr;
            }
            if (head == tail) {
                head = pre;
            }
            delete tail;
            tail = pre;
        }
    }

private:
    void moveToHead(Node *node) {
        if (node == nullptr || node == head) {
            return;
        }
        if (node->pre) {
            node->pre->next = node->next;
        }
        if (node->next) {
            node->next->pre = node->pre;
        } else {
            tail = node->pre;
        }
        node->pre = nullptr;
        node->next = head;
        head->pre = node;
        head = node;
    }

private:
    std::unordered_map<int, Node *> umap;  // <key, Node*>
    Node *head{nullptr};
    Node *tail{nullptr};
    int capacity;
};

int main() {
    LRUCache cache(2);
    std::cout << cache.get(1) << std::endl;
    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << cache.get(2) << std::endl;
    cache.put(3, 30);
    std::cout << cache.get(1) << std::endl;
    return 0;
}