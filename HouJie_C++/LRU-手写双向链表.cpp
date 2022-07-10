//LeetCode 146.LRU

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <climits>
// #define MAX_VAL 0x7fffffff

using namespace std;

class Node {
public:
    int key, val;
    Node* pre;
    Node* next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        pre = nullptr;
        next = nullptr;
    }
};

class doubleList {
public:
    doubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        size = 0;
    }
    // 尾插法
    void addLast(Node* node) {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
        size++;
    }
    // 删除节点且保证node一定存在
    void remove(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        size--;
    }
    // 删除链表中第一个节点，并返回该节点: 返回的原因是在删除最近最少使用节点后，还要知道节点的key来删除map中的值
    Node* removeFirst() {
        if (head->next == tail) return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }
    // 返回链表长度
    int getSize() {
        return size;
    }

private:
    Node* head;
    Node* tail;
    int size;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->cache = new doubleList();
    }

    int get(int key) {
        if (mp.count(key) == 0) return -1;
        makeRecently(key);
        return mp[key]->val;
    }

    void put(int key, int val) {
        if (mp.count(key) > 0) {
            mp[key]->val = val;
            makeRecently(key);
        }
        else {
            Node* node = new Node(key, val);
            if (cache->getSize() >= cap) {
                removeLeastRecently();
            }
            cache->addLast(node);
            mp[key] = node;
        }
    }

private:
    // 在map和doubleList两种数据结构提供一层抽象API，可以同时对两种数据结构进行操作，避免操作了一种数据结构却忘记对另一种进行操作的情况发生
    // 把某个key提升为最近使用
    void makeRecently(int key) {
        Node* node = mp[key];
        cache->remove(node);
        cache->addLast(node);
    }

    // 添加最近使用的元素
    void addRecently(int key, int val) {
        Node* node = new Node(key, val);
        cache->addLast(node);
        mp[key] = node;
    }
    // 删除某个key
    void deleteKey(int key) {
        Node* node = mp[key];
        cache->remove(node);
        mp.erase(key);
    }
    // 删除最近未使用的元素
    void removeLeastRecently() {
        Node* node = cache->removeFirst();
        int deleteKey = node->key;
        mp.erase(deleteKey);
    }

private:
    int cap;
    map<int, Node*> mp;
    doubleList* cache;
};