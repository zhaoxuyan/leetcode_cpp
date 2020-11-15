/*
 * 39. 组合总和
 * 给定一个无重复元素的数组candidates和一个目标数target，
 * 找出candidates中所有可以使数字和为target的组合。
 * candidates中的数字可以无限制重复被选取。
 *
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 *   [7],
 *   [2,2,3]
 * ]
 *
 * 解析：
 * https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
 *
 * 排列问题，讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为不同列表时），
 * 需要记录哪些数字已经使用过，此时用 used 数组；
 *
 * 组合问题，不讲究顺序（即 [2, 2, 3] 与 [2, 3, 2] 视为相同列表时），
 * 需要按照某种顺序搜索，此时使用 begin 变量。

 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> res;
        if (len == 0) return res;

        // 路径
        vector<int> path;
        dfs(candidates, path, 0, res, len, target);
        return res;
    }
    /**
     *
     * @param candidates 候选数组
     * @param path 路径
     * @param begin 搜索起点
     * @param res 结果
     * @param len 候选数组长度
     * @param target 每减去一个元素 目标值变小
     */
    void dfs(vector<int>& candidates, vector<int>& path, int begin, vector<vector<int>>& res, int& len, int target) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < len; ++i) {
            // 每一次搜索的时候设置 下一轮搜索的起点 begin，请看下图。
            path.push_back(candidates[i]);
            // 注意：由于每一个元素可以重复使用，下一轮搜索的起点依然是 i，这里非常容易弄错
            dfs(candidates, path, i, res, len, target - candidates[i]);
            path.pop_back();
        }
    }
};