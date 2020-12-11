/*
 * 567. 字符串的排列
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 *
 * 输入: s1 = "ab" s2 = "eidbaooo"
   输出: True
   解释: s2 包含 s1 的排列之一 ("ba").
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::string t = s1;
        std::string s = s2;

        int left, right = 0;
        int start = 0;
        int len = INT16_MAX;
        int valid = 0;

        for (auto& c : t) need[c]++;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            // 开始收缩
            // 与0076的不同之处
            // 子串 不是 子序列
            while (right - left >= t.size()) {
                // // 与0076的不同之处
                if (valid == need.size()) {
                    return true;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }

private:
    unordered_map<char, int> window, need;
};