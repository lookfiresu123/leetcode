#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
    //int sum = 0;
    struct TreeNode *current = root;
    if(!current)
        return false;
    else if(current->val == sum && !current->left && !current->right)
        return true;
    else{
        return hasPathSum(current->left,sum-current->val) || hasPathSum(current->right,sum-current->val);
    }
}
