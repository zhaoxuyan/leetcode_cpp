/*
 * 92. 反转链表 II
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 *
 *
 * 题解：
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/
 * 双重递归...
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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        // 不是从1 开始 就给他递归到从1开始
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
    // 从第一个节点开始，反转链表的前n个节点
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

private:
    ListNode* successor = nullptr;
};
