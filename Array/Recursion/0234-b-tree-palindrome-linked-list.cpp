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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 借助二叉树后序遍历的思路，不需要显式反转原始链表也可以倒序遍历链表，
    bool isPalindrome(ListNode *head) {
        left = head;
        return traverse(head);
    }
    bool traverse(ListNode *right) {
        // base case
        if (right == nullptr) return true;
        // 压栈
        bool res = traverse(right->next);

        // 后序遍历代码
        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }

private:
    ListNode *left;
};