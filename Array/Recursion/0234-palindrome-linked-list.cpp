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
class Solution {
public:
    void isPalindrome(ListNode *head) {
//
//        ListNode* right = head;
        ListNode* left = head;
        ListNode* right = reverseList(head);
//        bool isPali = true;

        right = right->next;
        cout<<"right: "<<right->val;


//
        left = left->next;
        cout<<"left: "<<left->val;



//        while (head) {
//            if (head->val == reverse->val) {
//                cout<<"head->val: "<<head->val<<endl;
//                cout<<"reverse->val: "<<reverse->val<<endl;
//                head = head->next;
//                reverse = reverse->next;
//            } else{
//                cout<<"here"<<endl;
//                return false;
//            }
//
//        }
//        return true;
    }
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

int main() {
    Solution solution;
    vector<int> node{1, 1, 2, 1};
    auto *head = myGenerateListWithoutExtraHead(node);
    solution.isPalindrome(head);
}