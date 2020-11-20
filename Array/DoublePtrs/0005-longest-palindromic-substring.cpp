/*
 * 5. 最长回文子串
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 * 输入: "cbbd"
 * 输出: "bb"
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        // 给定字符串"a" 结果为a 呵呵了 这tm是回文？
        // 好嘛
        string res = s.substr(0, 1);
        for (int i = 0; i < n; ++i) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
    string palindrome(string &s, int l, int r) {
        while (l >= 0 && r < s.size()) {
            if (s[l] == s[r]) {
                // 向两边展开
                l--;
                r++;
            } else
                break;
        }
        // substr第二参数如果为 0 或负数，将返回一个空字符串。
        return s.substr(l + 1, r - l - 1);
    }
};