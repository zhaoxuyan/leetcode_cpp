/*
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke"是一个子序列 不是子串。

 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;

        while (right < s.size()) {
            char c = s[right];
            right++;
            // 没有need了
            window[c]++;
            // 如果存在重复元素 则收缩窗口
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            // 在这里更新答案
            // 收缩完成后 保证没有重复元素
            res = max(res, right - left);
        }
        return res;
    }
};