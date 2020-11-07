/**
 * 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * 输出：6
 * 解释：
 * 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
 * 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
 * 因为当拨动到 "0102" 时这个锁就会被锁定。
 */

/**
 * 比如说从 "0000" 开始，
 * 转一次，可以穷举出 "1000", "9000", "0100", "0900"... 共 8 种密码。
 * 然后，再以这 8 种密码作为基础，对每个密码再转一下，穷举出所有可能...
 * 仔细想想，这就可以抽象成一幅图，每个节点有 8 个相邻的节点，又让你求最短距离，这不就是典型的 BFS 嘛
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    static string plusOne(string str, int i){
        if(str[i] == '9')
            str[i] = '0';
        else
            str[i] += 1;
        return str;
    }
    static string minusOne(string str, int i){
        if(str[i] == '0')
            str[i] = '9';
        else
            str[i] -= 1;
        return str;
    }


    int openLock(vector<string>& deadends, string target) {
        // 死亡值
        unordered_set<string> deads(deadends.begin(), deadends.end());

        // 定义队列
        queue<string> q;
        q.push("0000");

        // 记录已经访问过的
        unordered_set<string> visited;
        visited.insert("0000");

        // 全局step
        int step = 0;
        while(!q.empty()){
            int queue_size = q.size();
            // 一层一层的遍历
            for(int i = 0; i < queue_size; ++i){
                string cur = q.front();
                q.pop();
                if (deads.count(cur))
                    continue;
                if (cur == target)
                    return step;
                for(int j = 0; j < 4; ++j){
                    // +1
                    string plusOneStr = plusOne(cur, j);
                    if (!visited.count(plusOneStr)){
                        q.push(plusOneStr);
                        visited.insert(plusOneStr);
                    }

                    // -1
                    string minusOneStr = minusOne(cur, j);
                    if (!visited.count(minusOneStr)){
                        q.push(minusOneStr);
                        visited.insert(minusOneStr);
                    }
                }

            }
            // 遍历队列的for循环外面, 在此处++
            step++;
        }
        return -1;
    }
};