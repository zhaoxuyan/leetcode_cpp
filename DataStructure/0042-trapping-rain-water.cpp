/*
 * 42. trapping-rain-water
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
 * 计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int trap_baoli(vector<int>& height) {
        int n = height.size();
        int res;
        for (int i = 1; i < n - 1; ++i) {
            int l_max, r_max = 0;
            // 右边最高的柱子
            for (int j = i; j < n; ++j) {
                r_max = max(r_max, height[j]);
            }
            // 左边最高的柱子
            for (int j = i; j >= 0; --j) {
                l_max = max(l_max, height[j]);
            }
            int water = min(l_max, r_max) - height[i];
            water = water <= 0 ? 0 : water;
            res += water;
        }
        return res;
    }
    /**
     * memo 时间复杂度O（N） 空间复杂度O（N）
     * @param height
     * @return
     */
    int trap_memo(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int res = 0;
        // 数组充当备忘录
        vector<int> l_max(n), r_max(n);
        // 初始化base case
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        // 从左向右计算l_max
        for (int i = 1; i < n; i++) {
            l_max[i] = max(height[i], l_max[i - 1]);
        }
        // 从右向左计算r_max
        for (int i = n - 2; i >= 0; i--) {
            r_max[i] = max(height[i], r_max[i + 1]);
        }
        // 计算答案
        for (int i = 1; i < n - 1; ++i) {
            res += min(l_max[i], r_max[i]) - height[i];
        }
        return res;
    }
    /**
     * 双指针 时间复杂度O（N） 空间复杂度O（1）
     * @param height
     * @return
     */
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int l_max = height[0];
        int r_max = height[n - 1];
        while (left <= right) {
            l_max = max(height[left], l_max);
            r_max = max(height[right], r_max);
            if (l_max < r_max) {
                res += l_max - height[left];
                left++;
            } else {
                res += r_max - height[right];
                right--;
            }
        }
        return res;
    }
};