#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        ListNode *current = head;
        while (current) {
            vec.push_back(current->val);
            current = current->next;
        }
        int lo = 0, hi = vec.size()-1;
        TreeNode *root = createNode(vec, lo, hi);
        return root;
    }
private:
    TreeNode *createNode(vector<int> &vec, int lo, int hi) {
        TreeNode *root = NULL;
        if (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            root = new TreeNode(vec[mid]);
            root->left = createNode(vec, lo, mid-1);
            root->right = createNode(vec, mid+1, hi);
        }
        return root;
    }
};
