#include <iostream>
#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool compare(TreeNode *left_node, TreeNode *right_node) {
        if (!left_node && !right_node)
            return true;
        else if (!left_node || !right_node)
            return false;
        else if (left_node->val == right_node->val)
            return compare(left_node->left, right_node->right) && compare(left_node->right, right_node->left);
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else
            return compare(root->left, root->right);
    }
};
