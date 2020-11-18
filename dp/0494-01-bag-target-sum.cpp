/*
 * 494. 目标和
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号+和-。
 * 对于数组中的任意一个整数，你都可以从+或-中选择一个符号添加在前面。
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/target-sum
 *
 *输入：nums: [1, 1, 1, 1, 1], S: 3
 * 输出：5
 * 解释：
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 *
 * 分析：
 * 其实，这个问题可以转化为一个子集划分问题，
 * 而子集划分问题又是一个典型的背包问题
 *
 * 首先，如果我们把 nums 划分成两个子集 A 和 B，
 * 分别代表分配 + 的数和分配 - 的数，
 * 那么他们和 target 存在如下关系
 *
 * sum(A) - sum(B) = target
 * sum(A) = target + sum(B)
 * sum(A) + sum(A) = target + sum(B) + sum(A)
 * 2 * sum(A) = target + sum(nums)
 *
 * 综上，可以推出 sum(A) = (target + sum(nums)) / 2，
 * 也就是把原问题转化成：nums 中存在几个子集 A，
 * 使得 A 中元素的和为 (target + sum(nums)) / 2？
 *
 *
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum < S || (sum + S) % 2 != 0) {
            return 0;
        }

        // 开始01背包
        // 有几种凑法 能刚好凑满重量为(target + sum(nums)) / 2的背包
        int n = nums.size();
        int W = (sum + S) / 2;
        int dp[n + 1][W + 1];
        memset(dp, 0, sizeof(dp));

        // base case
        dp[0][0] = 1;
        //        for (int i = 0; i <= n; ++i) {
        //            dp[i][0] = 1;
        //        }

        for (int i = 1; i <= n; ++i) {
            // 从0开始
            for (int w = 0; w <= W; ++w) {
                if (w - nums[i - 1] < 0) {
                    dp[i][w] = dp[i - 1][w];
                } else {
                    dp[i][w] = dp[i - 1][w] + dp[i - 1][w - nums[i - 1]];
                }
            }
        }
        return dp[n][W];
    }
};
