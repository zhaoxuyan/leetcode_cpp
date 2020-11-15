/**
 * 46. 全排列
 * Given a collection of distinct integers, return all possible permutations.
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 *
 * Example:
 * Input: [1,2,3]
 * Output:
 *   [
 *     [1,2,3],
 *     [1,3,2],
 *     [2,1,3],
 *     [2,3,1],
 *     [3,1,2],
 *     [3,2,1]
 *   ]
 */

/**
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
            backtrack(路径, 选择列表)
        撤销选择
**/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 路径
        vector<int> track;
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
        for (int i = 0; i < nums.size(); ++i) {
            // 排除不合法的选择 这里其实就是检查used
            if (find(track.begin(), track.end(), nums[i]) != track.end()) continue;
            // 做选择
            track.push_back(nums[i]);
            // 进入下一层决策树
            dfs(nums, track);
            // 取消选择
            track.pop_back();
        }
    }

private:
    vector<vector<int>> res;
};