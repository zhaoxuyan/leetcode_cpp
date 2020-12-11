/**
 * 392. 判断子序列
 *
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 *
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 有顺序 不能用滑动窗口模板
// 例如输入: "acb" "ahbgdc" 应该返回false 滑动窗口会返回true
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 注意int i,j = 0
        // i会被初始化成一个垃圾值
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == s.size();
    }
};
