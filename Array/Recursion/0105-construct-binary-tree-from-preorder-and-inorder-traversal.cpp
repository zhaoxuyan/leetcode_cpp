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
/*
 * 解析：
 * https://mp.weixin.qq.com/s/OlpaDhPDTJlQ5MJ8tsARlA
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
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if(pre_start > pre_end){
            return nullptr;
        }
        // 前序的第一个元素是根节点
        int root_val = preorder[pre_start];
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
        root->left = build(preorder, pre_start + 1, pre_start + left_size,
                           inorder, in_start, index - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end,
                            inorder, index + 1, in_end);
        return root;
    }
};