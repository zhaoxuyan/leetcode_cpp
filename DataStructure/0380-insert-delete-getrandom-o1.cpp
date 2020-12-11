/*
 * 380. 常数时间插入、删除和获取随机元素
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** 如果 val 不存在集合中，则插入并返回 true，否则直接返回 false */
    bool insert(int val) {}

    /** 如果 val 在集合中，则删除并返回 true，否则直接返回 false */
    bool remove(int val) {}

    /** 从集合中等概率地随机获得一个元素 */
    int getRandom() {}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */