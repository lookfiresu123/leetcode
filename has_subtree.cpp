#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2)   // neither pRoot1 nor pRoot2 should be NULL
            return false;
        return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
private:
    // determine whether pRoot1 contain pRoot2 begin at the root
    bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot2)
            return true;
        else if (!pRoot1 || pRoot1->val != pRoot2->val)
            return false;
        else
            return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
    }
};
