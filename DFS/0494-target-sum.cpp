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
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    //回溯法超时
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        int res = 0;
        backtrack(nums, 0, S, res);
        return res;
    }
    void backtrack(vector<int>& nums, int i, int& rest, int& res) {
        if (i == nums.size()) {
            if (rest == 0) {
                res++;
            }
            return;
        }
        // 给nums[i]选择 + 号
        rest -= nums[i];
        backtrack(nums, i + 1, rest, res);
        rest += nums[i];

        // 给nums[i]选择 - 号
        rest += nums[i];
        backtrack(nums, i + 1, rest, res);
        rest -= nums[i];
    }
};