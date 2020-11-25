/*
 * 230. 二叉搜索树中第K小的元素
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 *
 * 输入: root = [3,1,4,null,2], k = 1
       3
      / \
     1   4
      \
       2
    输出: 1


    输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
    输出: 3

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
    int kthSmallest(TreeNode *root, int k) {
        traverse(root, k);
        return res;
    }
    void traverse(TreeNode *root, int k) {
        if (!root) {
            return;
        }
        traverse(root->left, k);
        // 二叉搜索树性质：中序遍历是升序
        rank++;
        if (k == rank) {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }

private:
    int res = 0;
    int rank = 0;
};