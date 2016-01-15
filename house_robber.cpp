#include <vector>
#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    std::deque<int> dq;     // 用于存储nums，并创建树
    TreeNode *root;
public:
    using pTreeNode = TreeNode *;
    // 拷贝nums到dq中，并在首部加入元素0
    void copy(vector<int> &nums) {
        for (int i : nums)
            dq.push_back(i);
        dq.push_front(0);
    }

    void create_tree(pTreeNode &root, std::deque<int> dq) {

    }

    int rob(vector<int> &nums) {
        copy(nums);
        create_tree(root, dq);
        return 0;
    }
};

int main () {
    return 0;
}
