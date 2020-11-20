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
/*
void myGenerateList(ListNode *list, vector<int> &vec) {
    for (const auto &v : vec) {
        ListNode *node = new ListNode(v);
        list->next = node;
        list = node;
    }
}
ListNode *myGenerateListWithoutExtraHead(vector<int> &vec) {
    auto *pHead = new ListNode(0);
    myGenerateList(pHead, vec);
    auto *pRet = pHead->next;
    delete pHead;
    pHead = nullptr;
    return pRet;
}
 */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> org;
        // 注意!!!
        // 不能直接操作head
        auto *left = head;
        while (left != nullptr) {
            org.push_back(left->val);
            left = left->next;
        }

        ListNode *right = reverseList(head);

        for (int i = 0; i < org.size(); ++i) {
            if (org[i] == right->val) {
                right = right->next;
            } else {
                return false;
            }
        }
        return true;
    }
    // 这样做会改变原始链表的结构 破坏head
    // 所以要先用一个vector把原先的head链表保存下来
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = nullptr;
        ListNode *pre = head;

        while (pre != nullptr) {
            ListNode *temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};
/*
int main() {
    Solution solution;
    vector<int> node{1, 1, 2, 1};
    auto *head = myGenerateListWithoutExtraHead(node);
    solution.isPalindrome(head);
}
*/