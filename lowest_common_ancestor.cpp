#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    TreeNode *insert(int val) {
        TreeNode *new_node = new TreeNode(val);
        return new_node;
    }

    bool search_path_for(TreeNode *current_root, TreeNode *target, vector<TreeNode *> &target_path) {
        if (current_root) {
            target_path.push_back(current_root);
            if (current_root != target) {
                if (!current_root->left && !current_root->right) {
                    target_path.pop_back();
                    return false;
                } else {
                    bool flag_left = search_path_for(current_root->left, target, target_path);
                    bool flag_right = search_path_for(current_root->right, target, target_path);
                    if (!flag_left && !flag_right) {
                        target_path.pop_back();
                        return false;
                    } else
                        return true;
                }
            } else
                return true;
        } else
            return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path_p, path_q;
        // search path for p
        search_path_for(root, p, path_p);
        // search path for q
        search_path_for(root, q, path_q);
        // print path_p and path_q
        for (auto i = path_p.begin() ; i != path_p.end() ; ++i)
            cout << (*i)->val << ", ";
        cout << endl;
        for (auto i = path_q.begin() ; i != path_q.end() ; ++i)
            cout << (*i)->val << ", ";
        cout << endl;
        // reverse path_p and path_q
        reverse(path_p.begin(), path_p.end());
        reverse(path_q.begin(), path_q.end());
        auto t = find_first_of(path_p.begin(), path_p.end(), path_q.begin(), path_q.end());
        if (t == path_p.end())
            return nullptr;
        return (*t);
    }
};

int main () {
    TreeNode *root = nullptr;
    Solution sol;
    root = sol.insert(6);
    root->left = sol.insert(2);
    root->right = sol.insert(8);
    root->left->left = sol.insert(0);
    root->left->right = sol.insert(4);
    root->right->left = sol.insert(7);
    root->right->right = sol.insert(9);
    root->left->right->left = sol.insert(3);
    root->left->right->right = sol.insert(5);
    TreeNode *result = sol.lowestCommonAncestor(root, root->left->right->left, root->left->right->right);
    cout << result->val << endl;
    return 0;
}
