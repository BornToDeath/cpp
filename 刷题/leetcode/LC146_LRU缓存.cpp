//
// Created by lixiaoqing on 2022/7/4.
//

#include <iostream>
#include <unordered_map>
#include <list>

/**
 * 方法2：自定义链表节点，节点包含 key, val 以及 该节点的前驱和后继
 * 关键：哈希链表，即 std::unordered_map + 双向链表。map 存储所有的 <key, value> ，便于进行 O(1) 时间复杂度查找，双向链表用于存储 LRU 节点
 */
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (map.count(key) == 0) {
            return -1;
        }
        erase(key);
        push_back(key);
        return map[key]->val;
    }

    void put(int key, int value) {
        if (map.count(key) == 0) {
            if (map.size() == capacity) {
                pop_front();
            }
            auto node = new Node(key, value);
            map[key] = node;
            push_back(key);
        } else {
            erase(key);
            push_back(key);
            map[key]->val = value;
        }
    }

private:

    void push_back(int key) {
        auto node = map[key];
        node->pre = tail->pre;
        node->pre->next = node;
        node->next = tail;
        tail->pre = node;
    }

    void pop_front() {
        auto node = head->next;
        head->next = node->next;
        head->next->pre = head;
        node->next = nullptr;
        node->pre = nullptr;
        map.erase(node->key);
        delete node;
    }

    void erase(int key) {
        auto node = map[key];
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

private:

    class Node {
    public:
        Node(int key, int val) : key(key), val(val), next(nullptr), pre(nullptr) {}

    public:
        int key;
        int val;
        Node *next;
        Node *pre;
    };

    int capacity;
    std::unordered_map<int, Node *> map;
    Node *head;
    Node *tail;
};

/**
 * 方法1：借助 STL std::list ，不AC，时间超限
 */
//class LRUCache {
//public:
//    LRUCache(int capacity) : capacity(capacity) {
//
//    }
//
//    int get(int key) {
//        if (map.find(key) == map.end()) {
//            return -1;
//        }
//        list.erase(std::find(list.begin(), list.end(), key));
//        list.push_back(key);
//        return map[key];
//    }
//
//    void put(int key, int value) {
//        if (map.find(key) == map.end()) {
//            if (list.size() == capacity) {
//                map.erase(list.front());
//                list.pop_front();
//            }
//            list.push_back(key);
//            auto ele = std::find(list.begin(), list.end(), 1);
//        } else {
//            list.erase(std::find(list.begin(), list.end(), key));
//            list.push_back(key);
//        }
//        map[key] = value;
//    }
//
//private:
//    int capacity;
//    std::unordered_map<int, int> map;
//    std::list<int> list;
//};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lru(2);
//    lru.put(1, 1);
//    lru.put(2, 2);
//    std::cout << lru.get(1) << std::endl;
//    lru.put(3, 3);
//    std::cout << lru.get(2) << std::endl;
//    lru.put(4, 4);
//    std::cout << lru.get(1) << std::endl;
//    std::cout << lru.get(3) << std::endl;
//    std::cout << lru.get(4) << std::endl;

    lru.put(2, 1);
    lru.put(1, 1);
    lru.put(2, 3);
    lru.put(4, 1);
    std::cout << lru.get(1) << std::endl;
    std::cout << lru.get(2) << std::endl;

    return 0;
}