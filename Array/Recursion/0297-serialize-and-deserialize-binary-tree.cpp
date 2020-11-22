/*
 * 297. 二叉树的序列化与反序列化
 *
 * 你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserialize(ss);
    }

private:
    void serialize(TreeNode* root, ostringstream& ss) {
        if (!root) {
            ss << "# ";
            return;
        }

        ss << to_string(root->val) << " ";
        serialize(root->left, ss);
        serialize(root->right, ss);
    }

    TreeNode* deserialize(istringstream& ss) {
        TreeNode* root;
        string str;
        ss >> str;
        if (str == "#") {
            root = nullptr;
        } else {
            root = new TreeNode(stoi(str));
            auto left = deserialize(ss);
            auto right = deserialize(ss);
            root->left = left;
            root->right = right;
        }

        return root;
    }
};
