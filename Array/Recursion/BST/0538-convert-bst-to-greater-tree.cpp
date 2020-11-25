/*
 * 538. 把二叉搜索树转换为累加树
 * 给出二叉 搜索 树的根节点，该树的节点值各不相同，
 * 请你将其转换为累加树（Greater Sum Tree），
 * 使每个节点 node的新值等于原树中大于或等于node.val的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

注：这道题跟leetcode 1038一模一样
 */


#include <algorithm>
#include <iostream>
#include <sstream>
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

// 二叉搜索树中序遍历是升序
// 先右子树后左子树的中序遍历是降序
class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        traverse(root);
        return root;
    }

private:
    void traverse(TreeNode* root){
        if(!root) return;
        // 先右子树后左子树的中序遍历是降序
        traverse(root->right);
        // 中序遍历开始
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
    int sum;
};