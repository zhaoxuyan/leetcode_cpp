/*
 *
 * 解析：https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/2.3-shou-ba-shou-shua-er-cha-shu-xun-lian-di-gui-si-wei/er-cha-sou-suo-shu-cao-zuo-ji-jin
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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key){
            // 情况1和情况2
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;

            // 情况3
            // A 有两个子节点，麻烦了，为了不破坏 BST 的性质，
            // A 必须找到左子树中最大的那个节点，或者右子树中最小的那个节点来接替自己。我们以第二种方式讲解。
            TreeNode* min_node = getMin(root->right);
            // 把 root 改成 minNode
            root->val = min_node->val;
            // 转而去删除 minNode
            root->right = deleteNode(root->right, min_node->val);
        }
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
    TreeNode* getMin(TreeNode* node) {
        // BST 最左边的就是最小的
        while (node->left != nullptr) node = node->left;
        return node;
    }
};