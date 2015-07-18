#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int find_p_or_q = 0;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *current = root;
    struct TreeNode *result;
    if(!current)
        result = NULL;
    else{
        if(current == p || current == q){
            find_p_or_q++;
            result = current;
            lowestCommonAncestor(current->left,p,q);
            lowestCommonAncestor(current->right,p,q);
            if(find_p_or_q == 1)
                result = NULL;
        }
        else{
            result = lowestCommonAncestor(current->left,p,q);
            if(find_p_or_q == 0){
                result = lowestCommonAncestor(current->right,p,q);
                if(find_p_or_q == 1 || find_p_or_q == 0)
                    result = NULL;
            }
            else if(find_p_or_q == 1){
                result = lowestCommonAncestor(current->right,p,q);
                if(find_p_or_q == 1)
                    result = NULL;
                else
                    result = current;
            }
        }
    }
    return result;
}

int main(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 2;
    root->left->val = 1;
    root->right->val =3;
    root->left->left->val = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;
    struct TreeNode *result;
    result = lowestCommonAncestor(root,root->left,root->left->left);
    printf("%d\n",result->val);
    return 0;
}

