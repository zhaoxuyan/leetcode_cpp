/*
 * 416. 分割等和子集
 * 给定一个只包含正整数的非空数组。
 * 是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * 输入: [1, 5, 11, 5]
 * 输出: true
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 *
 * 输入: [1, 2, 3, 5]
 * 输出: false
 * 解释: 数组不能分割成两个元素和相等的子集.
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // dp[i][w] = true: 对于前i个物品，当前背包容量为w时，恰好将背包装满
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        // 如果是奇数 肯定不能平分 返回false
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        int n = nums.size();
        bool dp[n + 1][sum + 1];
        // base case
        dp[0][0] = false;
        // base case
        for (int i = 1; i <= n; ++i) {
            // 容量为0 已经装满了
            dp[i][0] = true;
        }
        // base case
        for (int w = 1; w <= sum; ++w) {
            dp[0][w] = false;
        }

        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= sum; ++w) {
                if (w - nums[i - 1] < 0) {
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // 有一个为true 就为true
                    dp[i][w] = dp[i - 1][w] | dp[i - 1][w - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};