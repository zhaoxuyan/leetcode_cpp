/**
 * 27. 移除元素
 * 给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 *
 * 示例1：
 * 给定 nums = [3,2,2,3], val = 3,
 * 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 * 你不需要考虑数组中超出新长度后面的元素。
 *
 * 示例2：
 * 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
 * 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 * 注意这五个元素可为任意顺序。
 * 你不需要考虑数组中超出新长度后面的元素。
 *
 * 注意与0026（有序数组）的区别
 * 注意这里和有序数组去重的解法有一个重要不同，
 * 我们这里是先给 nums[slow] 赋值然后再给 slow++，
 * 这样可以保证 nums[0..slow-1] 是不包含值为 val 的元素的，
 * 最后的结果数组长度就是 slow。
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                // 注意与0026的区别 先赋值再++
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};