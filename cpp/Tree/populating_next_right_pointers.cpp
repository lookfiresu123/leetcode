#include <iostream>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root && root->left) {
            root->left->next = root->right;
            if (root->next)
                root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
    }
};
