#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // 数学推导 画图 见labuladong
                // 当慢的追上快的时候，令任意一个等于头，然后再以相同速度前进。
                // 当再次相遇时，则为链表环的起点
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};