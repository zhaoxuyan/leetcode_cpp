#ifndef __UTILS_MY_LIST_UTIL__
#define __UTILS_MY_LIST_UTIL__

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

using std::vector;
using std::pair;

// defined by leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

// my util functions
/**
 * @brief Generate a link list from a given array
 *
 * The generated link list starts with a empty head, which doesn't have a valid
 * value (head->val is meaningless), the first actual valid element is head->next
 *
 * @param[out]  list  stores the head of generated link list
 * @param       arr   input array
 * @param       n     valid elements count of link list (array length)
 */
inline void myGenerateList(ListNode *list, int* arr, int n) {
    for(auto i = 0; i < n; ++i) {
        ListNode *node = new ListNode(arr[i]);
        list->next = node;
        list = node;
    }
}

// @override
inline void myGenerateList(ListNode *list, vector<int> &vec) {
    for (const auto &v : vec) {
        ListNode *node = new ListNode(v);
        list->next = node;
        list = node;
    }
}

// generate link list directly, without an extra head
inline ListNode *myGenerateListWithoutExtraHead(vector<int> &vec) {
    auto *pHead = new ListNode(0);
    myGenerateList(pHead, vec);
    auto *pRet = pHead->next;
    delete pHead; pHead = nullptr;
    return pRet;
}

/**
 * @brief Display all element values of a link list from the given start node
 *
 * If input node is head(empty node), it's value(which is invalid) will also be
 * printed.
 *
 * @param   p   start node of the link list
 */
inline void myDispList(ListNode *p) {
    while (p != nullptr) {
        std::cout << p->val << " -> ";
        p = p->next;
    }
    std::cout << "nullptr" << std::endl;
};

#endif // __UTILS_MY_LIST_UTIL__