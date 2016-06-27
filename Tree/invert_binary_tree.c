#include<stdio.h>
#include<stdlib.h>

/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     struct TreeNode *left;
 **     struct TreeNode *right;
 ** };
 **/

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct TreeNode* temp;
    if(current){
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        invertTree(current->left);
        invertTree(current->right);
    }
    return root;
}
