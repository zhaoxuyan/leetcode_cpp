/*
 * 114. 二叉树展开为链表
 * 给定一个二叉树，原地将它展开为一个单链表。
 * 输入：
 *      1
       / \
      2   5
     / \   \
    3   4   6

    输出：
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
 */

/*
 * 题解：
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/114-er-cha-shu-zhan-kai-wei-lian-biao-by-ming-zhi-/
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    // flatten:将一个二叉树，原地将它展开为链表
    // 输入 root；输出 无
    void flatten(TreeNode* root) {
        if(!root)
            return;
        // 将根节点的左子树变成链表
        flatten(root->left);
        // 将根节点的右子树变成链表
        flatten(root->right);
        // 开始拼接了兄弟们
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        // 找到树最右边的节点
        while (root->right != nullptr) root = root->right;
        root->right = temp;
    }
};