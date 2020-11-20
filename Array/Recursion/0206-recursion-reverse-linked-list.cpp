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

class Solution {
public:
    /*
     * 递归函数定义：输入一个节点head
     * 将[以head为起点]的链表反转，并返回反转后的头结点(last)
     */
    ListNode* reverseList(ListNode* head) {
        // base case
        if (head == nullptr || head->next == nullptr) return head;
        // 1 ->   reverse(2->3->4->5->6->NULL)
        // head
        ListNode* last = reverseList(head->next);
        // 1 ->   2<-3<-4<-5<-6
        // head   NULL       last
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};