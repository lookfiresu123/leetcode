#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorderTraversal_helper(TreeNode *root, vector<int> &result) {
        if (root) {
            inorderTraversal_helper(root->left, result);
            result.push_back(root->val);
            inorderTraversal_helper(root->right, result);
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorderTraversal_helper(root, result);
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    for (vector<int>::size_type i = 0 ; i < result.size() ; ++i)
        cout << result[i] << " ";
    cout << endl;
    delete root->right->left;
    delete root->right;
    delete root;
    return 0;
}
