#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // k 无限制，可以认为k是正无穷，此时k-1和k是一样的
        // 所以可以约掉所有的k
        if (prices.empty()) return 0;
        int n = prices.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
                continue;
            }
            if (i == 1) {
                // 需要重新推导
                dp[1][0] = max(0, -prices[0] + prices[1]);
                dp[1][1] = max(-prices[0], -prices[1]);
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
