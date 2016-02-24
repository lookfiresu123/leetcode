#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorderTraversal_helper(TreeNode *root, vector<int> &result) {
        if (root) {
            result.push_back(root->val);
            preorderTraversal_helper(root->left, result);
            preorderTraversal_helper(root->right, result);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderTraversal_helper(root, result);
        return result;
    }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->right =  new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> temp = sol.preorderTraversal(root);
    for (vector<int>::size_type i = 0 ; i < temp.size() ; ++i)
        cout << temp[i] << " ";
    cout << endl;
    delete root->right->left;
    delete root->right;
    delete root;
    return 0;
}
