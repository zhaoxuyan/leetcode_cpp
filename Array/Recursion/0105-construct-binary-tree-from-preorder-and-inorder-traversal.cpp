/*
 * 105. 从前序与中序遍历序列构造二叉树
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 * 返回如下的二叉树：
 *
 *      3
       / \
      9  20
        /  \
       15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end,
                    vector<int>& inorder, int in_start, int in_end){
        // 前序的第一个元素是根节点
        int root_val = preorder[pre_start];
        // 中序的索引
        int index = 0;
        for (int i = in_start; i <= in_end ; ++i) {
            if(inorder[i] == root_val){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder,pre_start+1,)
    }
};