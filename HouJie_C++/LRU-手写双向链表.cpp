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
    // β�巨
    void addLast(Node* node) {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
        size++;
    }
    // ɾ���ڵ��ұ�֤nodeһ������
    void remove(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        size--;
    }
    // ɾ�������е�һ���ڵ㣬�����ظýڵ�: ���ص�ԭ������ɾ���������ʹ�ýڵ�󣬻�Ҫ֪���ڵ��key��ɾ��map�е�ֵ
    Node* removeFirst() {
        if (head->next == tail) return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }
    // ����������
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
    // ��map��doubleList�������ݽṹ�ṩһ�����API������ͬʱ���������ݽṹ���в��������������һ�����ݽṹȴ���Ƕ���һ�ֽ��в������������
    // ��ĳ��key����Ϊ���ʹ��
    void makeRecently(int key) {
        Node* node = mp[key];
        cache->remove(node);
        cache->addLast(node);
    }

    // ������ʹ�õ�Ԫ��
    void addRecently(int key, int val) {
        Node* node = new Node(key, val);
        cache->addLast(node);
        mp[key] = node;
    }
    // ɾ��ĳ��key
    void deleteKey(int key) {
        Node* node = mp[key];
        cache->remove(node);
        mp.erase(key);
    }
    // ɾ�����δʹ�õ�Ԫ��
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