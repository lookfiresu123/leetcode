#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void push(vector<int> &v, TreeNode *root) {
        if (root) {
            push(v, root->left);
            v.push_back(root->val);
            push(v, root->right);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        // 中序遍历
        push(v, root);
        // 返回第k-1个元素
        return v[k-1];
    }
};
