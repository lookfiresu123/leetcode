#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

/* 序列化及反序列化二叉树 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string ret;
        if (!root)
            return ret;
        deque<TreeNode *> dq;
        dq.push_back(root);
        TreeNode *tmp = NULL;
        while (!dq.empty()) {
            tmp = dq.front();
            if (tmp) {
                ret = ret + to_string(tmp->val) + ',';
                dq.push_back(tmp->left);
                dq.push_back(tmp->right);
            } else
                ret = ret + "#,";
            dq.pop_front();
        }
        ret.pop_back(); // delete the last ','
        // cout << "ret = " << ret << endl;
        return ret;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        TreeNode *root = NULL;
        if (data.empty())   return root;
        stringstream input(data);
        string word;
        deque<string> dq1;
        deque<TreeNode *> dq2;
        while (getline(input, word, ','))
            dq1.push_back(word);
        root = new TreeNode(stoi(dq1.front()));
        dq2.push_back(root);
        dq1.pop_front();
        TreeNode *tmp = NULL;
        // BFS
        while (!dq1.empty()) {
            while (!dq2.empty()) {
                tmp = dq2.front();
                dq2.pop_front();
                if (dq1.front() != "#") {
                    tmp->left = new TreeNode(stoi(dq1.front()));
                    dq2.push_back(tmp->left);
                    // dq1.pop_front();
                }
                dq1.pop_front();
                if (dq1.front() != "#") {
                    tmp->right = new TreeNode(stoi(dq1.front()));
                    dq2.push_back(tmp->right);
                }
                dq1.pop_front();
            }
        }
        // clear dq2
        dq2.clear();
        return root;
    }
};

