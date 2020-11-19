/**
 * 19. 删除链表的倒数第N个节点
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        // 让快指针先前进n步
        while (n-- > 0) {
            fast = fast->next;
        }
        // 特殊情况
        if (fast == nullptr) {
            // 如果此时fast 为空
            // 说明倒数第n个结点就是头结点
            return head->next;
        }
        // 再以相同速度前进
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // 删除倒数第n个元素
        slow->next = slow->next->next;
        return head;
    }
};