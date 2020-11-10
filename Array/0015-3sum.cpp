/*
 * 给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，
 * 使得a + b + c = 0 ？
 * 请你找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 *
 * 分析：以为是返回元素的值 所以可以排序用双指针
 * 题目中要求不重复，排序后必须做特殊处理来去重(while)
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 数组排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        // 穷举3sum的第一个数
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> tuples = twoSumTarget(nums, i + 1, 0 - nums[i]);
            for (auto& tuple : tuples) {
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            // 必须要跳过第一个数字重复的情况，否则会出现重复结果
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }

    vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {
        int left = start;
        int right = nums.size() - 1;
        vector<vector<int>> res;
        while (left < right) {
            int sum = nums[left] + nums[right];
            int left_value = nums[left];
            int right_value = nums[right];
            if (sum < target) {
                while (left < right && nums[left] == left_value) left++;
            } else if (sum > target) {
                while (left < right && nums[right] == right_value) right--;
            } else {
                res.push_back({left_value, right_value});
                // 跳过所有重复元素
                while (left < right && nums[left] == left_value) left++;
                while (left < right && nums[right] == right_value) right--;
            }
        }
        return res;
    }
};