/*
 * 31. 下一个排列
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 必须 原地 修改，只允许使用额外常数空间。
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 *
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 *
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 *
 * 输入：nums = [1]
 * 输出：[1]
 *
 *
 * 1. 先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
 * 2. 再找出另一个最大索引 l 满足 nums[l] > nums[k]；
 * 3. 交换 nums[l] 和 nums[k]
 * 4. 最后翻转 nums[k+1:]
 *
 * 1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last
 * permutation.
 * 2. Find the largest index l greater than k such that a[k] < a[l].
 * 3. Swap the value of a[k] with that of a[l].
 * 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = 0;
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                flag = true;
            }
        }

        if (!flag) {
            reverse(nums.begin(), nums.end());
        } else {
            int l = k;
            for (int i = k + 1; i < nums.size(); ++i) {
                if (nums[i] > nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2};
    solution.nextPermutation(nums);
}
