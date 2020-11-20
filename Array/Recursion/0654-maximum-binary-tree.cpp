/*
 * 654. 最大二叉树
 *
 * 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
 * 二叉树的根是数组中的最大元素。
 * 左子树是通过数组中最大值左边部分构造出的最大二叉树。
 * 右子树是通过数组中最大值右边部分构造出的最大二叉树。
 * 通过给定的数组构建最大二叉树，并且输出这个树的根节点。
 *
 *
 * 输入：[3,2,1,6,0,5]
   输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    /
     2  0
       \
        1

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int left, int right) {
        // base case
        if (left > right) return nullptr;

        // 找到最大值的下标
        int index = -1;
        int max_value = INT8_MIN;
        for (int i = left; i <= right; ++i) {
            if (nums[i] > max_value) {
                index = i;
                max_value = nums[i];
            }
        }
        TreeNode* root = new TreeNode(max_value);
        root->left = build(nums, left, index - 1);
        root->right = build(nums, index + 1, right);
        return root;
    }
};