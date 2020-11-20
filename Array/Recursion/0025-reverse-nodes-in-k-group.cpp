/*
 * 25. K 个一组翻转链表
 * 给你一个链表，每k个节点一组进行翻转，请你返回翻转后的链表。
 * k是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * 给你这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 *
 * 解析:
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/di-gui-si-wei-ru-he-tiao-chu-xi-jie-by-labuladong/
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode* a;
        ListNode* b;
        a = b = head;
        // base case
        // b往后走k步, 看是否还有k个元素待处理
        for (int i = 0; i < k; ++i) {
            // 若不足k个 则不需要反转
            if (b == nullptr) return head;
            b = b->next;
        }
        // 此时a = head, b已经往后走了k步
        // 反转前 k 个元素
        ListNode* new_head = reverseList(a, b);
        // 递归反转后续链表 并拼接
        a->next = reverseKGroup(b, k);
        return new_head;
    }

    // 反转head到b之间的节点
    // 0206改写
    // [head, b)
    ListNode* reverseList(ListNode* head, ListNode* b) {
        ListNode* cur = nullptr;
        ListNode* pre = head;
        // 0206
        // while (pre != nullptr)
        while (pre != b) {
            ListNode* temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};