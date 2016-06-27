/*
 * =====================================================================================
 *
 *       Filename:  same_tree.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月26日 15时55分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

/* Definition for a binary tree node. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)
        return true;
    else if ( (!p && q) || (p && !q) )
        return false;
    return (p->val == q->val ? true : false) &&
           (isSameTree(p->left, q->left))    &&
           (isSameTree(p->right, q->right));
}
