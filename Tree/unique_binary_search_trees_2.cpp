#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode *>();

        vector<vector<TreeNode *> > result(n+1);
        result[0].push_back(NULL);  // when the sum of nodes is 0, the structurally unique BST is NULL

        for (int i = 1 ; i <= n ; ++i) {
            // result[i] stores all the structurally unique BST which sum of nodes is i
            for (int j = 0 ; j < i ; ++j) {
                for (TreeNode *nodeL : result[j]) {
                    // construct left subtree based all the structurally unique BST which sum of nodes is j
                    for (TreeNode *nodeR : result[i-j-1]) {
                        // construct right subtree based all the structurally unique BST which sum of nodes is i-j-1
                        TreeNode *node = new TreeNode(j+1);
                        node->left = nodeL;
                        node->right = clone(nodeR, j+1);
                        result[i].push_back(node);
                    }
                }
            }
        }
        return result[n];
    }

private:
    TreeNode *clone(TreeNode *root, int offset) {
        if (!root)
            return NULL;
        TreeNode *node = new TreeNode(root->val + offset);
        node->left = clone(root->left, offset);
        node->right = clone(root->right, offset);
        return node;
    }
};

int main() {
    return 0;
}
