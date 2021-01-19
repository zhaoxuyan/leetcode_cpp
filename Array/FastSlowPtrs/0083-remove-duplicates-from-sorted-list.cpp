/**
 * 83. 删除排序链表中的重复元素
 * 输入: 1->1->2
 * 输出: 1->2
 *
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

// 关联0026

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *slow = head, *fast = head;

        while (fast != nullptr) {
            if (fast->val != slow->val) {
                // nums[slow] = nums[fast];
                slow->next = fast;
                // slow++;
                slow = slow->next;
            }
            // fast++
            fast = fast->next;
        }
        // 断开与后面重复元素的连接
        slow->next = nullptr;
        return head;
    }
};