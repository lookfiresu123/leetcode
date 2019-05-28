#include <vector>
#include <deque>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void rightSideView_helper(vector<int> &ret, deque<TreeNode *> &dq, TreeNode *root) {
        if (root) {
            dq.push_back(root);
            TreeNode *per = dq.back();
            TreeNode *cur = NULL;
            while (!dq.empty()) {
                cur = dq.front();
                dq.pop_front();
                if (cur->left)      dq.push_back(cur->left);
                if (cur->right)     dq.push_back(cur->right);
                if (cur == per)  {
                    ret.push_back(per->val);
                    if (!dq.empty())    per = dq.back();
                }
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        deque<TreeNode *> dq;
        rightSideView_helper(ret, dq, root);
        return ret;
    }
};
