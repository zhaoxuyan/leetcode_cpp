/**
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。
 * 该数列由 0 和 1开始，后面的每一项数字都是前面两项数字的和。也就是：
 * F(0) = 0, F(1) = 1 F(N) = F(N - 1) + F(N -2), 其中 N > 1.
 */
#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * 动态规划
     * @param N
     * @return
     */
    int fib_dp(int N) {
        std::vector<int> dp(N + 1, 0);
        // base case
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
    /**
     * 递归
     * @param N
     * @return
     */
    int fib(int N) {
        if (N < 1) return 0;
        std::vector<int> memo(N + 1, 0);
        return helper(memo, N);
    }
    int helper(std::vector<int>& memo, int n) {
        // base case
        if (n == 1 || n == 2) return 1;
        // 已经计算过
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
        return memo[n];
    }
};