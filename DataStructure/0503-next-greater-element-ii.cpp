/*
 * 503. 下一个更大元素 II
 *
 *  输入: [1,2,1]
    输出: [2,-1,2]
    解释: 第一个 1 的下一个更大的数是 2；
    数字 2 找不到下一个更大的数；
    第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 解析：这题跟496的区别是 这题是循环数组
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        // 存放结果
        vector<int> res(n);
        stack<int> s;
        // 假装扩大了2倍
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            // 当i小于n时，此时栈中有东西了, 会更新之前的值
            res[i % n] = (s.empty() ? -1 : s.top());
            s.push(nums[i % n]);
        }
        return res;
    }
};