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
private:
    unordered_map<char, int> window, need;
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;

        for(auto & c : s) need[c]++;
        int right = 0;
        int left = 0;
        int valid = 0;

        while (right < t.size()){
            char c = t[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            if (valid == need.size()){
                return true;
            }
        }
        return false;
    }
};