/*
 * 98. 验证二叉搜索树
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 输入:
        2
       / \
      1   3
   输出: true


 输入:
        5
       / \
      1   4
      /    \
     3      6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
根节点的值为 5 ，但是其右子节点值为 4 。

 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：先中序遍历 得到list 若是二叉搜索树则这个list是升序的
// 判断这个list是否是升序
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        traverse(root);
        if (res.empty()) return true;
        for (int i = 0; i < res.size() - 1; ++i) {
            if (res[i + 1] > res[i])
                continue;
            else
                return false;
        }
        return true;
    }

private:
    void traverse(TreeNode *root) {
        if (!root) return;
        traverse(root->left);
        res.push_back(root->val);
        traverse(root->right);
    }
    vector<int> res;
};