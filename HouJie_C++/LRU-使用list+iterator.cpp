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

// ʹ��ͷ�巨����Ϊ��˫�������½ڵ��
// ������뵽β���� ����mp[key]ʱ��end()ʵ����ָ�����˫���������һ��Ԫ�ص���һ��λ��
// ������뵽ͷ��������mp[key]ʱ��begin()ָ��ľ���˫�������һ��Ԫ�ص�λ��
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
    // pair<int, int> �൱��һ���ڵ㣬�У�key, value������
    list<pair<int, int>> cache;
    // iterator�൱��ָ��
    map<int, list<pair<int, int>>::iterator> mp;

};