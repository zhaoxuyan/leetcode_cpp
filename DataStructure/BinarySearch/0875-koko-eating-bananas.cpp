// 题目：https://leetcode-cn.com/problems/koko-eating-bananas/
// 二分法：https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/er-fen-cha-zhao-xiang-jie

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 普通硬核搜索 超时
    int minEatingSpeed_nomal(vector<int>& piles, int H) {
        int max = getMax(piles);
        // 连续的空间线性搜索，这是二分查找可以发挥作用的标志
        for (int speed = 1; speed < max; ++speed) {
            if (canFinish(piles, speed, H)) return speed;
        }
        return max;
    }

    // 由于我们要求的是最小速度, 所以可以用一个搜索左侧边界的二分查找来代替线性搜索
    int minEatingSpeed(vector<int>& piles, int H) {
        // 套用搜索左侧边界的算法框架
        int left = 1, right = getMax(piles);
        // 搜索区间为 [left, right]
        while (left <= right) {
            // 防止溢出
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, H)) {
                // 遇到符合条件的 收缩右侧边界
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // 辅助函数
    bool canFinish(vector<int>& piles, int speed, int H) {
        int time = 0;
        for (int n : piles) {
            time += timeOf(n, speed);
            if (time > H) return false;
        }
        return true;
    }

    int timeOf(int n, int speed) { return (n / speed) + ((n % speed > 0) ? 1 : 0); }

    int getMax(vector<int>& piles) {
        int max = 0;
        for (int n : piles) max = n > max ? n : max;
        return max;
    }
};