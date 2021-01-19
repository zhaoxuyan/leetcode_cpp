/*
 * 给定一个范围在 1 ≤ a[i] ≤ n (n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 *
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 输出:
 * [5,6]
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // HashSet 的解法时间复杂度是 O(N)，但是还需要 O(N) 的空间复杂度存储 HashSet。
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return {};
        unordered_set<int> set_;
        for(const auto& num: nums){
            set_.insert(num);
        }
        int n = nums.size();
        vector<int> res;
        for (int i = 1; i <= n; i ++){
            if(set_.count(i))
                continue;
            res.push_back(i);
        }
        return res;
    }
};