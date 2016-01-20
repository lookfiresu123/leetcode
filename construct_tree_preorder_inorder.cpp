/*
 * 105. construct binary tree from preorder and inorder traversal
 * */
#include <vector>
#include <cstdio>
#include <algorithm>
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
    TreeNode* buildTree(vector<int> &preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        else {
            // 前序遍历的第一个结点为当前树的根结点
            int root_val = preorder.front();
            TreeNode *root = new TreeNode(root_val);
            // 分别定义左右子树的前序序列和中序序列
            // 在中序序列中找到根节点的迭代器位置
            vector<int>::iterator iter = find(inorder.begin(), inorder.end(), root_val);
            // iter左边的为左子树的中序序列，右边的为右子树的中序序列
            vector<int> inorder_left(inorder.begin(), iter);    // 构造左子树的中序序列
            vector<int> inorder_right;
            if (iter != inorder.end()) {        // 构造右子树的中序序列
                for (auto it = iter + 1 ; it != inorder.end() ; ++it)
                    inorder_right.push_back(*it);
            }
            // 分别查找并构造左右子树的前序序列
            vector<int> preorder_left, preorder_right;
            // 查找并构造左子树的前序序列
            for (auto it = preorder.begin() + 1 ; it != preorder.end() ; ++it) {
                if (find(inorder_left.begin(), inorder_left.end(), *it) != inorder_left.end())
                    preorder_left.push_back(*it);
            }
            // 查找并构造右子树的前序序列
            for (auto it = preorder.begin() + preorder_left.size() + 1 ; it != preorder.end() ; ++it)
                preorder_right.push_back(*it);

            // 根据左右子树的前序序列和中序序列，分别构造当前树的左子树和右子树
            root->left = buildTree(preorder_left, inorder_left);
            root->right = buildTree(preorder_right, inorder_right);
            return root;
        }
    }
};

int main() {
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> inorder = {4,2,5,1,6,3,7};
    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);
    cout << "root->val : " << root->val << endl;
    cout << "root->left->val : " << root->left->val << endl;
    cout << "root->right->val : " << root->right->val << endl;
    cout << "root->left->left->val : " << root->left->left->val << endl;
    cout << "root->left->right->val : " << root->left->right->val << endl;
    cout << "root->right->left->val : " << root->right->left->val << endl;
    cout << "root->right->right->val : " << root->right->right->val << endl;
    return 0;
}
