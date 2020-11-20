/*
 * 226. 翻转二叉树
 * 翻转一棵二叉树。
 *
 * 输入：
 *       4
       /   \
      2     7
     / \   / \
    1   3 6   9

    输出：
         4
       /   \
      7     2
     / \   / \
    9   6 3   1
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return root;
        // 前序遍历
        swapNode(root);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    void swapNode(TreeNode* node) {
        if (!node || (!node->left && !node->right)) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};