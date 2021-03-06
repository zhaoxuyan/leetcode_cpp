/*
 * 518. 零钱兑换 II（完全背包问题）
 * 给定不同面额的硬币和一个总金额。
 * 写出函数来计算可以凑成总金额的硬币组合数。
 * 假设每一种面额的硬币有无限个。
 *
 * 输入: amount = 5, coins = [1, 2, 5]
 * 输出: 4
 * 解释: 有四种方式可以凑成总金额:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * 输入: amount = 3, coins = [2]
 * 输出: 0
 * 解释: 只用面额2的硬币不能凑成总金额3。
 *
 * 输入: amount = 10, coins = [10]
 * 输出: 1
 *
 *
 *
 *
 *
 * 分析：
 * 有一个背包，最大容量为amount，
 * 有一系列物品coins，每个物品的重量为coins[i]，每个物品的数量无限。
 * 请问有多少种方法，能够把背包恰好装满？
 *
 * 「完全背包」问题的特点是：背包里的物品可以无限次选取；
 * 本题特殊的地方在于：从背包里选取的物品 必须刚好装满需要考虑的容量，
 * 而不是小于等于，注意这点细微的区别。
 * 「完全背包」问题是「0-1」背包问题的扩展。它们的区别在于：
 * 「0-1」背包问题：当前考虑的物品拿或者不拿；
 * 「完全」背包问题：当前考虑的物品拿或者不拿，如果拿，只要背包能装下，就可以一直拿，直到背包装不下为止。
 * 「
 *
 * 力扣」 第 518 题：一个组合的不同排列在结果集中只出现一次，这一点是「背包问题」的特征，
 * 拿东西的顺序不重要。[2, 2, 1] 是一个组合，[1, 2, 2] 和 [2, 1, 2] 不是新的组合。
 * 这道题和「力扣」第 39 题：组合总和 很像，只不过：
 * 第 39 题问的是所有的组合列表，应该使用 回溯算法 求解；
 * 第 518 题问的是组合有多少种，而不是问具体的解。应该使用 动态规划 求解。
 * 作者：liweiwei1419
 * 链接：https://leetcode-cn.com/problems/coin-change-2/solution/dong-tai-gui-hua-wan-quan-bei-bao-wen-ti-by-liweiw/
 *
 * dp[i][j] 的定义如下：
 * 若只使用前 i 个物品，当背包容量为 j 时，有 dp[i][j] 种方法可以装满背包。
 *
 * base case 为 dp[0][..] = 0， dp[..][0] = 1。
 * 因为如果不使用任何硬币面值，就无法凑出任何金额；
 * 如果凑出的目标金额为 0，那么“无为而治”就是唯一的一种凑法。
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int W = amount;
        int n = coins.size();
        int dp[n + 1][W + 1];
        // base case
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int w = 1; w <= W; ++w) {
            dp[0][w] = 0;
        }
        // 问题的特殊点在于物品的数量是无限
        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= W; ++w) {
                // 不够装了，维持原状
                if (w - coins[i - 1] < 0) {
                    dp[i][w] = dp[i - 1][w];
                }else{
                    // 综上就是两种选择，
                    // 而我们想求的 dp[i][j] 是「共有多少种凑法」，
                    // 所以 dp[i][j] 的值应该是以上两种选择的结果之和：
                    // 不装 + 装
                    dp[i][w] = dp[i - 1][w] + dp[i][w - coins[i-1]];
                }
            }
        }
        return dp[n][W];
    }
};