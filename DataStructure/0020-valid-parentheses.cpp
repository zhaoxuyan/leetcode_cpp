/*
 * 20. 有效括号
 *
 * 用栈来解决
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    stack<char> stack;
    unordered_map<char, char> map = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'},
    };

public:
    bool isValid(string s) {
        for (auto& c : s) {
            if (map.count(c)) {
                // 如果是正括号
                stack.push(c);
            } else {
                // 如果是反括号
                // 注意条件有两个：
                // 1. 如果此时栈为空 说明没有正括号能跟这个反括号匹配 return false
                // 2. 栈顶的括号不匹配
                if (stack.empty() || map[stack.top()] != c) return false;
                // 记得c++要手动pop
                stack.pop();
            }
        }
        return stack.empty();
    }
};