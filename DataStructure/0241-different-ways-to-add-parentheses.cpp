/*
 * 241. 为运算表达式设计优先级
 * 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。
 * 你需要给出所有可能的组合的结果。有效的运算符号包含 +,-以及*。
 *
 *  示例1：
 *  输入: "2-1-1"
    输出: [0, 2]
    解释:
    ((2-1)-1) = 0
    (2-(1-1)) = 2


    示例2：
    输入: "2*3-4*5"
    输出: [-34, -14, -10, -10, 10]
    解释:
    (2*(3-(4*5))) = -34
    ((2*3)-(4*5)) = -14
    ((2*(3-4))*5) = -10
    (2*((3-4)*5)) = -10
    (((2*3)-4)*5) = 10

 *
 */

/*
 * 解法：递归+分治
 * 不考虑括号嵌套
 * (1) + (2 * 3 - 4 * 5)
 * (1 + 2) * (3 - 4 * 5)
 * (1 + 2 * 3) - (4 * 5)
 * (1 + 2 * 3 - 4) * (5)
 * 其实就是按照运算符进行分割，给每个运算符的左右两部分加括号
 *
 *
 */

/*
List<Integer> diffWaysToCompute("(1 + 2 * 3) - (4 * 5)") {
    List<Integer> res = new LinkedList<>();
    // 分
    List<Integer> left = diffWaysToCompute("1 + 2 * 3");
    List<Integer> right = diffWaysToCompute("4 * 5");
    // 治
    for (int a : left)
        for (int b : right)
            res.add(a - b);
    return res;
}
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // 函数签名：计算input所有可能的结果并放入vector<int>
    vector<int> diffWaysToCompute(string input) {
        int index = 0;
        // 如果输入一个运算符也没有 纯数字
        while (index < input.size() && isdigit(input[index])) index++;
        if (index == input.size()) return {stoi(input)};

        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            if (isOp(input[i])) {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));// 返回 [pos, size())
                for (int r1 : result1) {
                    for (int r2 : result2) {
                        ans.push_back(calculate(r1, input[i], r2));
                    }
                }
            }
        }
        return ans;
    }
    static bool isOp(const char& c) { return c == '+' || c == '-' || c == '*'; }

    static int calculate(const int& num1, const char& op, const int& num2) {
        if (op == '+')
            return num1 + num2;
        else if (op == '-')
            return num1 - num2;
        else
            return num1 * num2;
    }
};
