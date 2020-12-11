/*
 * 300. 最长上升子序列
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 *
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 *
 * 分析：注意子序列和子串的区别！
 * 子串一定是连续的。子序列不一定是连续的。
 *
 * dp数组含义：dp[i]表示以nums[i]结尾的最长递增子序列的长度
 *
 * 参考: https://mp.weixin.qq.com/s/7QFapCuvi-2nkh6gREcR9g
 * 分析:
 * index 0 1 2 3 4 5
 * nums  1 4 3 4 2 3
 * dp    1 2 2 3 2
 *
 * i = 5 nums[i] = 3,
 * 从 j = 0 ; j < i开始找nums[j] < nums[i]的
 * 推导： dp[5] = max{1+1, 2+1} = 3
 *
 * 解释：
 * base条件 dp[1] = 1 以nums[1]结尾的最长递增子序列的长度为1
 * nums[5] = 3，既然是递增子序列，
 * 我们只要找到前面那些结尾比 3 小的子序列，然后把 3 接到最后，
 * 就可以形成一个新的递增子序列，而且这个新的子序列长度加一。
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // dp[i]表示以nums[i]结尾的最长递增子序列的长度
    int lengthOfLIS(vector<int>& nums) {
        // 特殊情况
        if (nums.empty()) return 0;
        int dp[nums.size()];
        // 注意 memset只能初始化0或-1
        // 初始化其他值, 比如1, 要用fill !!!
        fill(dp, dp + nums.size(), 1);
        // base case: dp[0] = 1 解释：nums[0]结尾，只有一个元素，所以最长递增子序列的长度为1

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // 用max_element代替for
        return *max_element(dp,dp+nums.size());

        // 如果 int res = 0
        // for循环找最大值 就不用判断num.empty的情况
    }
};