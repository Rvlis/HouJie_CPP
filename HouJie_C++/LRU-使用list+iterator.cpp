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
#include <list>
// #define MAX_VAL 0x7fffffff

using namespace std;

// 使用头插法，因为在双向链表新节点后
// 如果插入到尾部， 更新mp[key]时，end()实际上指向的是双向链表最后一个元素的下一个位置
// 如果插入到头部，更新mp[key]时，begin()指向的就是双向链表第一个元素的位置
class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        auto node = *mp[key]; //pair<int,int>
        cache.erase(mp[key]);
        cache.push_front(node);
        mp[key] = cache.begin();
        return node.second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto node = *mp[key];
            cache.erase(mp[key]);
            node.second = value;
            cache.push_front(node);
            mp[key] = cache.begin();
        }
        else {
            if (cache.size() == cap) {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(pair<int, int>(key, value));
            mp[key] = cache.begin();
        }
    }

private:
    int cap;
    // pair<int, int> 相当于一个节点，有（key, value）属性
    list<pair<int, int>> cache;
    // iterator相当于指针
    map<int, list<pair<int, int>>::iterator> mp;

};