#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        // root 本身就是一层，depth 初始化为 1
        // 因为树的BFS遍历不会走回头路 所以不需要visited
        int depth = 1;

        while (!q.empty()) {
            /* 将当前队列中的所有节点向四周扩散 */
            for (int i = 0; i < q.size(); i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left == nullptr && cur->right == nullptr) return depth;
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};