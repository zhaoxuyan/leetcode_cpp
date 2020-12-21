/*
 * 前缀和
 * 560. 和为K的子数组
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 *
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    /* 正宗前缀和：超时
     * nums
     * index   0 1 2  3  4  5
     * value   3 5 2 -2  4  1
     *
     * Sum 前缀和
     * index 0 1 2 3  4  5  6
     * value 0 3 8 10 8  12 13
     *
     *
     */
    int subarraySum_pure(vector<int>& nums, int k) {
        int n = nums.size();
        int sum[n + 1];
        sum[0] = 0;
        // 计算前缀和数组
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        int res = 0;
        // i>j
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (sum[i] - sum[j] == k) {
                    res++;
                }
            }
        }
        return res;
    }

    // 前缀和 + 哈希表优化
    // 由于不需要记录i, j
    int subarraySum(vector<int>& nums, int k) {
        // key: 前0到i的和(前缀和)
        // value: 该和出现的次数
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, sum = 0;
        for (auto& x : nums) {
            sum += x;
            if (mp.find(sum - k) != mp.end()) {
                // 查找sum[i] - k = sum[j]
                // 且i > j
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};