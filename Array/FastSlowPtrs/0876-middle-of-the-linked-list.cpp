/*
 * 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
 * 如果有两个中间结点，则返回第二个中间结点。
 *
 * 输入：[1,2,3,4,5]
 * 输出：此列表中的结点 3
 *
 * 输入：[1,2,3,4,5,6]
 * 输出：此列表中的结点 4(偶数，中间靠右)
 *
 * 思路：慢指针一次前进一步 快指针一次前进两步
 * 当快指针到达链表尽头时 慢指针刚好停留在链表中点位置
 * 若链表长度为奇数 则停留在中间
 * 若链表长度为偶数 则停留在中间偏右
 */
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};