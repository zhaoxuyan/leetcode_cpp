/*
 * 106. 从中序与后序遍历序列构造二叉树
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 例如，给出
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, int in_start, int in_end,
                    vector<int>& postorder, int post_start, int post_end) {
        if(in_start > in_end){
            return nullptr;
        }
        // 后序遍历的最后一个元素是根节点
        int root_val = postorder[post_end];
        // 寻找中序根节点的索引
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == root_val) {
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(root_val);
        // 通过中序推导出来left_size
        int left_size = index - in_start;
        // 注意下标加1 减1 需要画图
        root->left = build(inorder, in_start, index - 1,
                           postorder, post_start, post_start + left_size - 1);
        root->right = build(inorder, index + 1, in_end,
                            postorder, post_start + left_size, post_end-1);
        return root;
    }
};