/*
 * 969. 煎饼排序
 *
 *  输入：[3,2,4,1]
    输出：[4,2,4,3]
    解释：
    我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
    初始状态 A = [3, 2, 4, 1]
    第一次翻转后 (k=4): A = [1, 4, 2, 3]
    第二次翻转后 (k=2): A = [4, 1, 2, 3]
    第三次翻转后 (k=4): A = [3, 2, 1, 4]
    第四次翻转后 (k=3): A = [1, 2, 3, 4]，此时已完成排序。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/pancake-sorting
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> res;

public:
    vector<int> pancakeSort(vector<int>& arr) {
        sort(arr,arr.size());
        return res;

    }
    void sort(vector<int>& arr, int n) {
        if (n == 1) return;

        int max_cake_index = max_element(arr.begin(), arr.begin() + n) - arr.begin();
        // cout<<"max_index:"<<max_cake_index;

        // 第一次翻转 将最大的饼翻到最上面
        reverse(arr.begin(), arr.begin() + max_cake_index + 1);
        res.push_back(max_cake_index + 1);
        // cout<<"第1次翻转";
        // for(auto e :arr) cout<<e<< " ";
        // 第二次翻转 翻转全部 将最大的饼放到最下面
        reverse(arr.begin(), arr.begin() + n);
        // cout<<"第2次翻转";
        // for(auto e :arr) cout<<e<< " ";
        res.push_back(n);
        sort(arr, n - 1);
    }
};