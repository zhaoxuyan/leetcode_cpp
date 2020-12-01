/*
 * 222. 完全二叉树的节点个数
 *
 * 给出一个完全二叉树，求出该树的节点个数。
 * 说明：
 * 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
 * 其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
 * 若最底层为第 h 层，则该层包含 1~2h个节点。
 *
 *
 * 输入:
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

 */
#include <algorithm>
#include <cmath>
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
    // 普通版本 遍历整颗二叉树 复杂度：O(N)
    int pure_countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + pure_countNodes(root->left) + pure_countNodes(root->right);
    }

    // 若树是满二叉树 复杂度：O(logN)
    int full_countNodes(TreeNode* root) {
        int h = 0;
        // 计算树的高度
        while (root != nullptr) {
            root = root->left;
            h++;
        }
        // 节点总数就是 2^h - 1
        return (int)pow(2, h) - 1;
    }

    // 完全二叉树 上述两种情况相结合 复杂度：O(logN*logN)

    // 直觉感觉好像最坏情况下是 O(N*logN) 吧，
    // 因为之前的 while 需要 logN 的时间，
    // 最后要 O(N) 的时间向左右子树递归：

    // 关键点在于，这两个递归只有一个会真的递归下去，
    // 另一个一定会触发hl == hr而立即返回，不会递归下去。
    // 因为一棵完全二叉树的两棵子树，至少有一棵是满二叉树：
    int countNodes(TreeNode* root) {
        TreeNode* l = root;
        TreeNode* r = root;
        int left_high = 0, right_high = 0;
        while (l != nullptr) {
            l = l->left;
            left_high++;
        }
        while (r != nullptr) {
            r = r->right;
            right_high++;
        }
        // 如果左右子树高度相等，则是一颗满二叉树
        if (left_high == right_high) {
            return int(pow(2, left_high)) - 1;
        }

        // 如果左右子树高度不等 则按普通二叉树计算
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};