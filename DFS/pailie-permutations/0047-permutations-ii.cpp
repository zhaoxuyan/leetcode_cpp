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

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> track;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<bool> used(len, false);
        backtrack(nums, used, track);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& track) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            // used[i-1] == false是对同一树枝不去重 对同一层去重
            // used[i-1] == true是对同一层不去重 对同一树枝去重
            // https://leetcode-cn.com/problems/permutations-ii/solution/47-quan-pai-lie-iiche-di-li-jie-pai-lie-zhong-de-q/
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, used, track);
            track.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};
    solution.permuteUnique(nums);
}