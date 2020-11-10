/*
 * 给定一个字符串 s 和一个非空字符串 p，
 * 找到 s 中所有是 p 的字母异位词的子串，
 * 返回这些子串的起始索引。
 *
 * 输入: s: "cbaebabacd" p: "abc"
 * 输出:
 * [0, 6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词
 *
 *
 * 分析；
 * 这个所谓的字母异位词，不就是排列吗，
 * 搞个高端的说法就能糊弄人了吗？
 * 相当于，输入一个串S，一个串T，找到S中所有T的排列，返回它们的起始索引。
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> window, need;
        int right, left = 0;
        int start = 0;
        int len = INT16_MAX;
        int valid = 0;

        for (auto& c : p) need[c]++;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 判断收缩条件
            // 子串 不是 子序列
            // 所有大小必须等于p
            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    // 更新结果
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};