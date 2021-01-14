/*
 * 43. 字符串相乘
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，
 * 返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 分析：https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/zi-fu-chuan-cheng-fa
 * 模拟最简单的人类小学乘法计算
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
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        // 结果最多为m+n位数
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // char -> int
                int mul = (num1[i] - '0') * (num2[j] - '0');
                // 乘积在res上对应的索引位置
                int p1 = i + j, p2 = i + j + 1;
                // 叠加到res上
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        int i = 0;
        // 排除掉前面未用到的0
        while (i < res.size() && res[i] == 0) i++;
        string res_str;
        for (; i < res.size(); i++) {
            // int -> char
            res_str.push_back(res[i] + '0');
        }
        return res_str.empty() ? "0" : res_str;
    }
};