/*
 * 集合 s 包含从 1 到n的整数。
 * 不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，
 * 导致集合 丢失了一个数字并且 有一个数字重复 。
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。
 * 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 *
 * 示例1：
 * 输入：nums = [1,2,2,4]
 * 输出：[2,3]
 *
 * 示例2：
 * 输入：nums = [1,1]
 * 输出：[1,2]
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 解析：
// 只有1个数字丢失 且 仅有1个数字重复
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        for (int i = 0; i < n; ++i) {
            // 元素从1开始
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                dup = abs(nums[i]);
            else
                nums[index] *= -1;
        }
        int missing = -1;
        for (int i = 0; i < n; i++)
            // nums[i] 大于 0 则说明没有访问
            if (nums[i] > 0) missing = i + 1;

        return {dup, missing};
    }
};