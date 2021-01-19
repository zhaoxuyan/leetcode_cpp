/*
 * 231. 2的幂
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 *
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 *
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 *
 * 解析：一个数如果是 2 的指数，那么它的二进制表示一定只含有一个 1：
 * 2^0 = 1 = 0b0001
 * 2^1 = 2 = 0b0010
 * 2^2 = 4 = 0b0100
 *
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};