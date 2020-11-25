/*
 * 701. 二叉搜索树中的插入操作
 * 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。
 * 返回插入后二叉搜索树的根节点。
 * 输入数据保证 ，新值和原始二叉搜索树中的任意节点值都不同。
 * 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。
 * 你可以返回任意有效的结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

class Solution {
public:
    // 一旦涉及「改」，函数就要返回 TreeNode 类型，
    // 并且对递归调用的返回值进行接收。
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // 找到空位置插入一个节点
        if (root == nullptr) return new TreeNode(val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        return root;
    }
};