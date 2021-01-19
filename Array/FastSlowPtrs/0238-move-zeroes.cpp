/**
 * 283. 移动零
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_nums_size = removeElement(nums, 0);
        for (; last_nums_size < nums.size(); ++last_nums_size) {
            nums[last_nums_size] = 0;
        }
    }
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