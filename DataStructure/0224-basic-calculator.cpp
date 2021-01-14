/*
 * 224. 基本计算器
 *
 * 输入：s = "1 + 1"
 * 输出：2
 *
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 *
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 可以假定输入的算式一定合法，
// 且计算过程不会出现整型溢出，不会出现除数为 0 的意外情况。
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }

    int helper(string &s, int &i) {
        stack<int> stk;
        int num = 0;
        char sign = '+';
        for (; i < s.size(); i++) {
            // 当前字符是空格, 如果不是字符最后的位置, 直接跳过
            if (s[i] == ' ' && i != (int)s.size() - 1) {
                continue;
            }

            // 当前字符是数字
            else if (isdigit(s[i])) {
                num = 10 * num + (s[i] - '0');
            }

            // 当前字符是 '('
            else if (s[i] == '(') {
                i++;
                num = helper(s, i);
                i++;
            }

            // 第一种情况, 遇到 '+' , '-' , '*' , '/', ')' 需要进行运算
            // 第二种情况, 遇到字符串的尾部 (尾部可能是一个数字, 可能是 ')' , 也可能是' ' , 所以这两种情况之间有重叠)
            if (!isdigit(s[i]) || i == s.size() - 1) {
                int pre;
                switch (sign) {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * num);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / num);
                    break;
                }

                // 只有递归过程才会遇到 ')', 上面运算完了需要额外进行 break
                if (s[i] == ')') {
                    break;
                }
                sign = s[i];
                num = 0;
            }
        }

        // 计算栈中所有元素的和
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }

    int string2int(string str) {
        int n = 0;
        for (char c : str) {
            // 因为变量c是一个 ASCII 码，
            // 如果不加括号就会先加后减，
            // 想象一下s如果接近 INT_MAX，就会溢出。
            // 所以用括号保证先减后加才行。
            n = 10 * n + (c - '0');
        }
        return n;
    }
};