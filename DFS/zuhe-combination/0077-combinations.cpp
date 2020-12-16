/*
 * 77. 组合
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *  输入: n = 4, k = 2
    输出:
    [
      [2,4],
      [3,4],
      [2,3],
      [1,2],
      [1,3],
      [1,4],
    ]
 *
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    int choose_k;

public:
    vector<vector<int>> combine(int n, int k) {
        choose_k = k;
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        vector<int> track;
        dfs(nums, 0, track);
        return res;
    }
    void dfs(vector<int>& nums, int start, vector<int>& track) {
        if(track.size() == choose_k){
            res.push_back(track);
        }
        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);
            dfs(nums, i + 1, track);
            track.pop_back();
        }
    }
};