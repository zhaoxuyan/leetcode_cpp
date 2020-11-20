/**
 * 234. 回文链表
 * 请判断一个链表是否为回文链表。
 *
 * 输入: 1->2
 * 输出: false
 *
 * 输入: 1->2->2->1
 * 输出: true
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
    // 利用快慢指针先找到中点，再反转后半部分
    bool isPalindrome(ListNode* head) {
        ListNode* slow = middleNode(head);
        ListNode* left = head;
        ListNode* right = reverseList(slow);
        while (right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        // left->next = reverseList(slow);
        return true;
    }

    // 反转链表
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
    // 寻找链表中心节点
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};