#include <deque>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        else {
            deque<TreeNode *> process_dq;       // 当前处理队列
            deque<TreeNode *> previous_dq;      // 保存之前的节点，用于将左右子树保存到process_dq中
            TreeNode *node;

            process_dq.push_back(root);
            while (!process_dq.empty()) {
                vector<int> current;
                while (!process_dq.empty()) {
                    node = process_dq.front();
                    // copy node to previous_dq
                    previous_dq.push_back(node);
                    // push node->val to current
                    current.push_back(node->val);
                    process_dq.pop_front();
                }
                result.push_back(current);
                // push the left and right tree of node in previous_dq to
                // process_dq and clear previous_dq
                while (!previous_dq.empty()) {
                    node = previous_dq.front();
                    if (node->left)
                        process_dq.push_back(node->left);
                    if (node->right)
                        process_dq.push_back(node->right);
                    previous_dq.pop_front();
                }
            }
            return result;
        }
    }
};

int main () {
    return 0;
}

