/*
 * 105. construct binary tree from postorder and inorder traversal
 * */
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     * @begin_postorder：后序序列的首迭代器
     * @end_postorder：后序序列的尾后迭代器
     * @begin_inorder：中序序列的首迭代器
     * @end_inorder：中序序列的尾后迭代器
     */
    TreeNode *buildTree_helper(vector<int>::iterator begin_postorder, vector<int>::iterator end_postorder,
                            vector<int>::iterator begin_inorder, vector<int>::iterator end_inorder) {
            if (begin_postorder == end_postorder || begin_inorder == end_inorder)
                return NULL;
            // 后序遍历的第一个结点为当前树的根结点
            int root_val = *(end_postorder-1);
            TreeNode *root = new TreeNode(root_val);

            // 分别查找左右子树的中序序列的边界
            // 首先在中序序列中找到根节点的迭代器位置
            vector<int>::iterator iter = find(begin_inorder, end_inorder, root_val);
            // iter左边的为左子树的中序序列，右边的为右子树的中序序列
            vector<int>::iterator left_begin_inorder = begin_inorder;       // 左子树的中序序列的首迭代器
            vector<int>::iterator left_end_inorder = iter;                  // 左子树的中序序列的尾后迭代器
            vector<int>::iterator right_begin_inorder = iter + 1;           // 右子树的中序序列的首迭代器
            vector<int>::iterator right_end_inorder = end_inorder;          // 右子树的中序序列的尾后迭代器
            // 分别查找左右子树的后序序列的边界，根据左右子树的中序序列和后序序列大小相同这一规则可以简单得到
            vector<int>::iterator left_begin_postorder = begin_postorder;                                               // 左子树的后序序列的首迭代器
            vector<int>::iterator left_end_postorder = left_begin_postorder + (left_end_inorder - left_begin_inorder);  // 左子树的后序序列的尾后迭代器
            vector<int>::iterator right_begin_postorder = left_end_postorder;                                           // 右子树的后序序列的首迭代器
            vector<int>::iterator right_end_postorder = end_postorder - 1;							                    // 右子树的后序序列的尾后迭代器
            // 根据左右子树的后序序列和中序序列，分别构造当前树的左子树和右子树
            root->left = buildTree_helper(left_begin_postorder, left_end_postorder, left_begin_inorder, left_end_inorder);
            root->right = buildTree_helper(right_begin_postorder, right_end_postorder, right_begin_inorder, right_end_inorder);
            return root;
    }

    TreeNode* buildTree(vector<int> &inorder, vector<int>& postorder) {
        TreeNode *root = buildTree_helper(postorder.begin(), postorder.end(),
                                    inorder.begin(), inorder.end());
        return root;
    }
};

int main() {
    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> inorder = {4,2,5,1,6,3,7};
    Solution sol;
    TreeNode *root = sol.buildTree(inorder, postorder);
    cout << "root->val : " << root->val << endl;
    cout << "root->left->val : " << root->left->val << endl;
    cout << "root->right->val : " << root->right->val << endl;
    cout << "root->left->left->val : " << root->left->left->val << endl;
    cout << "root->left->right->val : " << root->left->right->val << endl;
    cout << "root->right->left->val : " << root->right->left->val << endl;
    cout << "root->right->right->val : " << root->right->right->val << endl;
    return 0;
}
