/*
 * base case：
dp[-1][k][0] = dp[i][0][0] = 0
dp[-1][k][1] = dp[i][0][1] = -infinity

状态转移方程：
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 */

/**
 * 分析：
 * k = 2 和前面题目的情况稍微不同，因为上面的情况都和 k 的关系不太大。
 * 要么 k 是正无穷，状态转移和 k 没关系了；
 * 要么 k = 1，跟 k = 0 这个 base case 挨得近，最后也没有存在感。
 * 这道题 k = 2 和后面要讲的 k 是任意正整数的情况中，对 k 的处理就凸显出来了。
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // k = 2
        int max_k = 2;
        int n = prices.size();
        if (n == 0) return 0;
        int dp[n][max_k + 1][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i) {
            for (int k = max_k; k >= 1; --k) {
                if (i == 0) {
                    dp[0][k][0] = 0;
                    dp[0][k][1] = -prices[0];
                    continue;
                }

                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] =
                    max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][max_k][0];
    }
};