/*
 * 652. 寻找重复的子树
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，
 * 你只需要返回其中任意一棵的根结点即可。
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 *
 *  示例1：
 *          1
           / \
          2   3
         /   / \
        4   2   4
           /
          4

    输出：
          2
         /
        4
        和
        4
因此，你需要以列表的形式返回上述重复子树的根结点。
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        traverse(root);
        return res;
    }
    string traverse(TreeNode *root) {

        if (!root) {
            return "";
        }

        // 必须是后序遍历
        string left = traverse(root->left);
        string right = traverse(root->right);
        string ss;
        ss = to_string(root->val) + "," + left + "," + right;

        // 第一次freq = 0
        int freq = memo[ss];
        // 第一次是0，第二次是1
        // 如果有重复
        if (freq == 1) {
            res.push_back(root);
        }
        memo[ss] = freq + 1;
        return ss;
    }

private:
    unordered_map<string, int> memo;
    vector<TreeNode *> res;
};