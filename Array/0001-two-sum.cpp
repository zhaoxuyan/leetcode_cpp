/**
 * 给定一个整数数组 nums和一个目标值 target，
 * 请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 *
 *
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// 因为是返回下标 所以不能排序用双指针
// 且数组中只包含一个答案。“每种输入只会对应一个答案”
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // 数组中同一个元素不能使用两次
            // nums[i]放前面
            map.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < n; ++i) {
            int other = target - nums[i];
            // auto it = hashtable.find(target - nums[i]);
            // if (it != hashtable.end())
            if (map.count(other) && map[other] != i) {
                return {i, map[other]};
            }
        }
        return {};
    }
};