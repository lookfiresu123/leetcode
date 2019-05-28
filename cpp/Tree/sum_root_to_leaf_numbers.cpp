#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void get_totalpath(TreeNode *root, vector<string> &vec, string str) {
        str += to_string(root->val);
        if (!root->left && !root->right) {
            vec.push_back(str);
            return ;
        }
        if (root->left)
            get_totalpath(root->left, vec, str);
        if (root->right)
            get_totalpath(root->right, vec, str);
    }

    int sumNumbers(TreeNode* root) {
        vector<string> vec;
        string str;
        int ret = 0;
        if (!root)
            return ret;
        get_totalpath(root, vec, str);
        for_each(vec.begin(), vec.end(), [&ret](string &s){ if(!s.empty()) ret += stoi(s);});
        return ret;
    }
};
