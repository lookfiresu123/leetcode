#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int hl, hr;
        if ((hl = getHeight(root->left)) > (hr = getHeight(root->right)))
            return countNodes(root->left) + pow(2, hr);
        else
            return pow(2, hl) + countNodes(root->right);

    }
private:
    int getHeight(TreeNode *root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }
};
