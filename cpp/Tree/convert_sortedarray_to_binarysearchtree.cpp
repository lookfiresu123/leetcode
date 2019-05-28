#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST_helper(vector<int> &nums, vector<int>::size_type low_index, vector<int>::size_type high_index) {
        if (low_index <= high_index) {
            vector<int>::size_type mid_index = low_index + (high_index - low_index) / 2;
            TreeNode *root = new TreeNode(nums[mid_index]);
            if (mid_index > 0)
                root->left = sortedArrayToBST_helper(nums, low_index, mid_index-1);
            root->right = sortedArrayToBST_helper(nums, mid_index+1, high_index);
            return root;
        } else
            return NULL;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty())
            return NULL;
        TreeNode *root = sortedArrayToBST_helper(nums, 0, nums.size()-1);
        return root;
    }
};

int main() {
    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    vector<int> v2;
    Solution sol;
    sol.sortedArrayToBST(v1);
    sol.sortedArrayToBST(v2);
    return 0;
}
