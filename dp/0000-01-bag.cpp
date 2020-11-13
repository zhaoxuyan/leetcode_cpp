/*
 * 背包容量为W, 有N个物品
 * 其中第i个物品的重量为Wt[i] 价值为val[i]
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // dp[i][w] 对于前i个物品 当前背包容量为w时 装下最大价值为dp[i][w]的东西
    int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
        int dp[N + 1][W + 1];
        // base case 当容量W为0时，dp[0][..] = 0
        // base case 当物品N为0时，dp[..][0] = 0
        memset(dp, 0, sizeof(dp));
        // 因为i是从1开始 所有wt和val的取值都从i-1开始
        for (int i = 1; i <= N; ++i) {
            for (int w = 1; w <= W; ++w) {
                // 当前背包装不下了 选择不装入背包
                if (w - wt[i - 1] < 0) {
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // 选择不装入 or 装入
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1] + val[i - 1]]);
                }
            }
        }
        return dp[N][W];
    }
};