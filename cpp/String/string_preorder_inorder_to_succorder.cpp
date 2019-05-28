#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 利用前序遍历和中序遍历的字符串，计算后序遍历的字符串（假设每个字符只出现一次）
class Solution {
public:
    string getSuccOrder(const string &preorder, const string &inorder) {
        string succorder;
        succorder = getSuccOrder_helper(preorder, inorder);
        return succorder;
    }
private:
    string getSuccOrder_helper(string preorder, string inorder) {
        if (preorder.empty() || inorder.empty())
            return string();
        string succorder;
        int preorder_sz = preorder.length(), inorder_sz = inorder.length();
        char root_char = preorder[0];
        int pos = inorder.find(root_char);
        string inorder_lefttree(inorder.substr(0, pos));
        string inorder_righttree(inorder.substr(pos+1, inorder_sz-1-pos));
        string preorder_lefttree(preorder.substr(1, pos));
        string preorder_righttree(preorder.substr(pos+1, preorder_sz-1-pos));

        succorder = getSuccOrder_helper(preorder_lefttree, inorder_lefttree)
        + getSuccOrder_helper(preorder_righttree, inorder_righttree) + root_char;
        return succorder;
    }
};

int main() {
    Solution sol;
    string preorder, inorder;
    vector<string> ret;
    while (cin >> preorder >> inorder)
        ret.push_back(sol.getSuccOrder(preorder, inorder));
    for (int i = 0 ; i < ret.size() ; ++i)
        cout << ret[i] << endl;
    return 0;
}
