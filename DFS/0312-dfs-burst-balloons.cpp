#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 阶乘的时间复杂度
// 超时啦 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int coin = 0;
        int max_coin = 0;
        backtrack(nums, coin, max_coin);
        return max_coin;
    }
    void backtrack(vector<int>& nums, int& coin, int& max_coin) {
        if (nums.empty()) {
            max_coin = max(max_coin, coin);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int tempI = nums[i];
            int tempCoin = nums[i] * (i - 1 < 0 ? 1 : nums[i - 1]) * (i + 1 >= nums.size() ? 1 : nums[i + 1]);
            coin += tempCoin;
            // 戳破气球
            nums.erase(nums.begin() + i);
            backtrack(nums, coin, max_coin);
            // 回退
            // 重新插入回气球
            nums.insert(nums.begin() + i, tempI);
            coin -= tempCoin;
        }
    }
};