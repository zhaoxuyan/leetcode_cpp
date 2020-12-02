/*
 * 496. 下一个更大元素 I
 *  输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
    输出: [-1,3,-1]

    解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/next-greater-element-i
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 此算法叫：单调栈

 把数组的元素想象成并列站立的人，元素大小想象成人的身高。
 这些人面对你站成一列，如何求元素「2」的 Next Greater Number 呢？
 很简单，如果能够看到元素「2」，那么他后面可见的第一个人就是「2」的 Next Greater Number，
 因为比「2」小的元素身高不够，都被「2」挡住了，
 第一个露出来的就是答案。
 解析：
 https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.4-shou-ba-shou-she-ji-shu-ju-jie-gou/dan-tiao-zhan

 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        // key: nums2的值 , value: next greater element
        unordered_map<int, int> map;
        stack<int> s;

        // 单调栈模板
        // 倒着入栈
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                // 个子矮的滚
                s.pop();
            }
            map[nums2[i]] = s.empty() ? -1 : s.top();
            // 入栈
            s.push(nums2[i]);
        }

        for (auto& num : nums1) {
            if (map.count(num)) res.push_back(map[num]);
        }
        return res;
    }
};