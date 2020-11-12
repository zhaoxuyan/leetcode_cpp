/*
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数
 *
 * 你可以对一个单词进行如下三种操作：
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 * 解析：
 * 作者：ikaruga
 * 链接：https://leetcode-cn.com/problems/edit-distance/solution/edit-distance-by-ikaruga/

 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // dp[i][j]含义：word1在0到i(前i个字符) 变换到 word2在0到j(前j个字符) 需要最少的编辑距离
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        // base case 如果word2为空
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        // base case 如果word1为空
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
