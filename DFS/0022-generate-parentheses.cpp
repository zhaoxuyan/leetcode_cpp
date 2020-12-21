/*
 * 22. 括号生成
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *  输入：n = 3
    输出：[
           "((()))",
           "(()())",
           "(())()",
           "()(())",
           "()()()"
         ]
    分析：https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/3.1-hui-su-suan-fa-dfs-suan-fa-pian/he-fa-kuo-hao-sheng-cheng
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> res;

public:
    vector<string> generateParenthesis(int n) {
        vector<char> choice = {'(', ')'};
        string track;
        dfs(n, n, track);
        return res;
    }
    void dfs(int left, int right, string& track) {
        // 对于一个「合法」的括号字符串组合 p，
        // 必然对于任何 0 <= i < len(p) 都有：子串 p[0..i] 中左括号的数量都大于或等于右括号的数量。
        if (left > right) return;
        if (left < 0 || right < 0) return;
        // 一个「合法」括号组合的左括号数量一定等于右括号数量，这个很好理解。
        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        track.push_back('(');
        dfs(left - 1, right, track);
        track.pop_back();

        track.push_back(')');
        dfs(left, right - 1, track);
        track.pop_back();
    }
};