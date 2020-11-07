/*
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子序列。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 *
 *
 * 注意：
 * unordered_map可以使用方括号访问键对应的值map[key]。
 * 如果该key不存在，C++ 会自动创建这个 key，并把map[key]赋值为 0。
 *
 * 思路：
 * 1. 我们在字符串S中使用双指针中的左右指针技巧，初始化left = right = 0，
 * 把索引左闭右开区间[left, right)称为一个「窗口」
 *
 * 2. 我们先不断地增加right指针扩大窗口[left, right)，
 * 直到窗口中的字符串符合要求（包含了T中的所有字符）。
 *
 * 3. 此时，我们停止增加right，
 * 转而不断增加left指针缩小窗口[left, right)，
 * 直到窗口中的字符串不再符合要求（不包含T中的所有字符了）。
 * 同时，每次增加left，我们都要更新一轮结果。
 *
 * 4. 重复第 2 和第 3 步，直到right到达字符串S的尽头。
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        for (auto &c : t) need[c]++;
        int left = 0;
        int right = 0;
        // valid表示窗口中满足need条件的字符个数
        // 当valid = need.size() 说明窗口已经覆盖串t
        int valid = 0;

        // 记录最小子串的起始索引
        int start = 0;
        // 记录最小子串的长度
        int len = INT16_MAX;

        // 开始套路
        while (right < s.size()) {
            char c = s[right];
            // 右移窗口
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                // 在这里更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d 是即将移出窗口的字符
                char d = s[left];
                // 左指针向右移动
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT16_MAX ? "" : s.substr(start, len);
    }

private:
    unordered_map<char, int> need, window;
};