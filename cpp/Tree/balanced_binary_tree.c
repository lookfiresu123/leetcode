#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define max(x, y) ( (x) > (y) ? (x) : (y) )

int getHeight(struct TreeNode *root) {
    int height = 0;
    if (root)
        height = 1 + max(getHeight(root->left), getHeight(root->right));
    return height;
}

bool isBalanced(struct TreeNode* root) {
    if (root) {
        if (isBalanced(root->left) == false)
            return false;
        if (isBalanced(root->right) == false)
            return false;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
    }
    return true;
}

int main (void) {
    return 0;
}
