/*
 * 206. 反转链表
 * 反转一个单链表。
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 方法：迭代实现
 * 1. 定义两个指针： pre 和 cur ；pre 在前 cur 在后。
 * 2. 每次让 pre 的 next 指向 cur ，实现一次局部反转
 * 3. 局部反转完成之后，pre 和 cur 同时往前移动一个位置
 * 4. 循环上述过程，直至 pre 到达链表尾部
 *
 * 图：
 * NULL 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * cur  pre
 * 作者：huwt
 * 链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-shuang-zhi-zhen-di-gui-yao-mo-/

 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* pre = head;

        while (pre != nullptr) {
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};