/*
 * 136. 只出现一次的数字
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *
 * 输入: [2,2,1]
 * 输出: 1
 *
 * 输入: [4,1,2,1,2]
 * 输出: 4
 *
 * 一个数和它本身做异或运算结果为 0，即 a ^ a = 0；
 * 一个数和 0 做异或运算的结果为它本身，即 a ^ 0 = a。
 * 对于这道题目，我们只要把所有数字进行异或，成对儿的数字就会变成 0，落单的数字和 0 做异或还是它本身，
 * 所以最后异或的结果就是只出现一次的元素：
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(const auto& n : nums){
            res ^= n;
        }
        return res;
    }
};