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
 * 分析：题目的意思是找到字典序中大于该排序的下一个排序，
 * 也就是找到大于该排序的最小值，首先找出比末尾要小的数，
 * 如果找不到说明排序是降序，反转成升序，再找到比index位置大的数，
 * 交换之后再对交换后面的数据进行从小到大排序即可，代码如下：
 *
    作者：heroding
    链接：https://leetcode-cn.com/problems/next-permutation/solution/si-lu-zui-qing-xi-de-ti-jie-by-heroding/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size() - 1;
        // 找出比末尾要小的数
        while (index > 0 && nums[index] <= nums[index - 1]) {
            index--;
        }
        if (index == 0) {
            // 反转nums
            reverse(nums.begin(), nums.end());
        } else {
            int i = nums.size() - 1;
            // 找到比index位置大的数
            while (i > index && nums[i] <= nums[index - 1]) {
                i--;
            }
            swap(nums[index - 1], nums[i]);
            // 给index后的数据排序（从小到大）
            sort(nums.begin() + index, nums.end());
        }
    }
};
