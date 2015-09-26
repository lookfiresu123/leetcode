/*
 * =====================================================================================
 *
 *       Filename:  max_depth_of_binary_tree.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月26日 15时44分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

/* Definition for a binary tree node.*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;
    int depth_left;
    int depth_right;
    // the maxDepth_root = 1 + max { maxDepth_left, maxDepth_right }
    return 1 + ( (depth_left = maxDepth(root->left)) > (depth_right = maxDepth(root->right)) ? depth_left : depth_right);
}
