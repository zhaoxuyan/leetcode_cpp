/*
 * 47. 全排列II
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *  输入：nums = [1,1,2]
    输出：
    [[1,1,2],
     [1,2,1],
     [2,1,1]]
 *
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int, int> nums_count_map;
    unordered_map<int, int> used_map;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto& num : nums) nums_count_map[num]++;
        // 路径
        vector<int> track;
        // 排序
        sort(nums.begin(), nums.end());
        dfs(nums, track);
        return res;
    }
    /**
     * dfs
     * @param nums 可选路径
     * @param track  已选路径
     */
    void dfs(vector<int>& nums, vector<int> track) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        // 因为是组合 所以每次都从0开始
        for (int i = 0; i < nums.size(); ++i) {
            // 排除不合法的选择 这里其实就是检查used
            if (used_map[nums[i]] > 1 || used_map[nums[i]] >= nums_count_map[nums[i]]) continue;
            // 做选择
            track.push_back(nums[i]);
            used_map[nums[i]]++;
            // 进入下一层决策树
            dfs(nums, track);
            // 取消选择
            track.pop_back();
            used_map[nums[i]]--;
        }
    }
};