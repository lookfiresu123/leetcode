#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *root, string temp, vector<string> &vec) {
        if (!root)
            ;
        else {
            if (temp.empty())
                temp = std::to_string(root->val);
            else
                temp += ("->" + std::to_string(root->val));
            if (!root->left && !root->right)    // 若root结点为叶子结点，则push_back该路径
                vec.push_back(temp);
            else {
                dfs(root->left, temp, vec);
                dfs(root->right, temp, vec);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        string temp;    // temp初始化为空
        dfs(root, temp, vec);
        return vec;
    }
};
