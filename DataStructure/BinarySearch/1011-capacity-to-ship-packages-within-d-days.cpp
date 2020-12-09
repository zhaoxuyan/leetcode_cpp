#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = getMax(weights);
        int right = getSum(weights);
        // 求最小值：左侧边界二分搜索
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(weights, D, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int canFinish(vector<int>& weights, int D, int cap) {
        int i = 0;
        for (int day = 0; day < D; ++day) {
            // 每天的载重量都是cap个。
            int cur_cap = cap;
            // 按顺序i, 当天能装多少装多少 装不下了就下一天继续
            while (cur_cap - weights[i] >= 0) {
                cur_cap -= weights[i];
                i++;
                if (i == weights.size()) return true;
            }
        }
        return false;
    }
    int getMax(vector<int>& weights) {
        int max = 0;
        for (int n : weights) max = n > max ? n : max;
        return max;
    }
    int getSum(vector<int>& weights) {
        int sum = 0;
        for (auto& weight : weights) {
            sum += weight;
        }
        return sum;
    }
};