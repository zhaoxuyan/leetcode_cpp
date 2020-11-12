/*
 * 516. 最长回文子序列
 * 给定一个字符串 s ，找到其中最长的回文子序列，
 * 并返回该序列的长度。可以假设 s 的最大长度为 1000 。
 * 
 * 输入："bbbab"
 * 输出：4
 * 一个可能的最长回文子序列为 "bbbb"。
 *
 * 输入："cbbd"
 * 输出：2
 * 一个可能的最长回文子序列为 "bb"。
 *
 *
 * 分析：子序列subsequence比子串substring问题更复杂。
 * 因为子序列是不连续的，而子串是连续的。子序列不连续所以穷举几乎不可能
 *
 * 子序列问题一般涉及到两个字符串。比如最长公共子序列。
 * 一般问子序列和最值，就用动态规划，时间复杂度On2
 *
 * dp[i][j]定义：
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

    }
};