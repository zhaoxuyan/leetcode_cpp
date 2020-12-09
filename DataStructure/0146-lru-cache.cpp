/*
 * 分析：
 * 接收一个 capacity 参数作为缓存的最大容量，然后实现两个 API，
 * 一个是 put(key, val) 方法存入键值对，
 * 另一个是 get(key) 方法获取 key 对应的 val，如果 key 不存在则返回 -1。
 *
 *
 * 分析：LinkedHashMap + 链表的splice用法
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache {
public:
    //删除、查找、插入的复杂度都O（1）
    LRUCache(int capacity) { cap = capacity; }
    int get(int key) {
        if (hashtable.count(key) == 0)
            return -1;
        else {
            //更新到表头
            auto iter = hashtable[key];  //找到对应结点地址
            // 仅将 cache中的由迭代器 it 指向的元素移到cache的position处
            cache.splice(cache.begin(), cache, iter);  //移动到链表头
            return cache.begin()->second;              //返回value
        }
    }

    void put(int key, int value) {
        // 若key不存在
        if (hashtable.count(key) == 0) {
            // 如果容量满了, 删除尾部元素, 再加上新节点
            if (cache.size() == cap) {
                hashtable.erase(cache.back().first);
                cache.pop_back();
            }
            // 直接添加新节点
            cache.push_front(make_pair(key, value));
            hashtable[key] = cache.begin();
        } else {
            // 如果插入相同key的元素，除了要移动，value也需要更新
            auto iter = hashtable[key];
            iter->second = value;                      //更新地址value
            cache.splice(cache.begin(), cache, iter);  //移动到链表头
            hashtable[key] = cache.begin();            //更新hashtable的value
        }
    }
    unordered_map<int, list<pair<int, int>>::iterator> hashtable;
    list<pair<int, int>> cache;  // key value
    int cap = 0;                 // cache的容量
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
