#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void generateParenthesis_helper(vector<string> &vec, string s, int l, int r) {
        if (l <= r) {       // 剩余的右括号一定要大于或等于剩余的做括号
            if (l == 0 && r == 0)
                vec.push_back(s);       // 当左括号和右括号都没有时，将string压入vector中
            if (l > 0) {
                generateParenthesis_helper(vec, s+"(", l-1, r);     // 遍历整棵左子树
            }
            if (r > 0) {
                generateParenthesis_helper(vec, s+")", l, r-1);     // 遍历整棵右子树
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        if (n <= 0)
            return vec;
        generateParenthesis_helper(vec, string(), n, n);
        return vec;
    }
};

int main() {
    int n = 3;
    Solution sol;
    vector<string> vec = sol.generateParenthesis(n);
    for (vector<string>::size_type i = 0 ; i < vec.size() ; ++i)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}
