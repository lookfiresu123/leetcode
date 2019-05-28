#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode *> dq1, dq2;    // dq1从前打印，dq2从后打印

        vector<vector<int>> ret;
        if (!root)
            return ret;

        dq1.push_back(root);
        TreeNode *per = NULL;
        while (!dq1.empty() || !dq2.empty()) {
            vector<int> tmp1, tmp2;
            if (!dq1.empty()) {
                for (auto it = dq1.begin() ; it != dq1.end() ; ++it)
                    tmp1.push_back((*it)->val);
                ret.push_back(tmp1);
                while (!dq1.empty()) {
                    per = dq1.front();
                    dq1.pop_front();
                    if (per->left)  dq2.push_back(per->left);
                    if (per->right) dq2.push_back(per->right);
                }
            }
            if (!dq2.empty()) {
                for (auto it = dq2.rbegin() ; it != dq2.rend() ; ++it)
                    tmp2.push_back((*it)->val);
                ret.push_back(tmp2);
                while (!dq2.empty()) {
                    per = dq2.front();
                    dq2.pop_front();
                    if (per->left)  dq1.push_back(per->left);
                    if (per->right) dq1.push_back(per->right);
                }
            }
        }

        return ret;
    }
};
