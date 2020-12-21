/*
 * 78. 子集
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）
 * 说明：解集不能包含重复的子集。
 *
 * 输入：
 *  输入: nums = [1,2,3]
    输出:
    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]

    子集问题：每一个节点都要
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 记录走过的路
        vector<int> track;
        dfs(nums, 0, track);
        return res;
    }
    /**
     *
     * @param nums
     * @param start 因为是排列 所以需要记录start
     * @param track
     */
    void dfs(vector<int>& nums, int start, vector<int>& track) {
        // 直接加入结果结果中
        res.push_back(track);
        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);
            // 注意是i+1
            dfs(nums, i + 1, track);
            track.pop_back();
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3};
    solution.subsets(nums);
}