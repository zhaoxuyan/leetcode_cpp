/*
 * 700. 二叉搜索树中的搜索
 *
 * 给定二叉搜索树（BST）的根节点和一个值。
 * 你需要在BST中找到节点值等于给定值的节点。
 * 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
 *
 * 给定二叉搜索树:
        4
       / \
      2   7
     / \
    1   3
    和值: 2

你应该返回如下子树:
      2
     / \
    1   3
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) {
            return root;
        }
        // 不需要递归地搜索两边，类似二分查找思想，根
        // 据 target 和 root.val 的大小比较，就能排除一边。
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return nullptr;
    }
};