#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}

int minDepth(struct TreeNode* root){
    int depth = 0,cmp_lr,min_left,min_right;
    struct TreeNode *current = root;
    if(!current)
        return 0;
    else{
        min_left = minDepth(current->left);
        min_right = minDepth(current->right);
        if(min_left == 0 && min_right == 0)
            depth = 1;
        else if(min_left == 0 && min_right != 0)
            depth = 1 + min_right;
        else if(min_right == 0 && min_left != 0)
            depth = 1 + min_left;
        else{
            cmp_lr = min_left < min_right ? min_left : min_right;
            depth = cmp_lr + 1;
        }
         return depth;
     }
}
