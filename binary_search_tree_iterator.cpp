#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    vector<TreeNode *> vec;
    vector<TreeNode *>::size_type current;
public:
    void BSTIterator_helper(TreeNode *root) {
        if (root) {
            vec.push_back(root);
            BSTIterator_helper(root->left);
            BSTIterator_helper(root->right);
        }
    }

    BSTIterator(TreeNode *root) {
        BSTIterator_helper(root);
        sort(vec.begin(), vec.end(), [](TreeNode *p1, TreeNode *p2)->bool{ return p1->val <= p2->val; });
        current = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current < vec.size();
    }

    /** @return the next smallest number */
    int next() {
        return vec[current++]->val;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    BSTIterator i = BSTIterator(root);
    while(i.hasNext())  cout << i.next() << " ";
    cout << endl;
    return 0;
}
