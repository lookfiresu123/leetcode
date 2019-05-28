#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int tmp1, tmp2;
        for (int i = 0 ; i < tokens.size() ; ++i) {
            if (tokens[i] == string("+")) {
                tmp1 = stk.top(); stk.pop();
                tmp2 = stk.top(); stk.pop();
                stk.push(tmp2 + tmp1);
            } else if (tokens[i] == string("-")) {
                tmp1 = stk.top(); stk.pop();
                tmp2 = stk.top(); stk.pop();
                stk.push(tmp2 - tmp1);
            } else if (tokens[i] == string("*")) {
                tmp1 = stk.top(); stk.pop();
                tmp2 = stk.top(); stk.pop();
                stk.push(tmp2 * tmp1);
            } else if (tokens[i] == string("/")) {
                tmp1 = stk.top(); stk.pop();
                tmp2 = stk.top(); stk.pop();
                stk.push(tmp2 / tmp1);
            } else
                stk.push(stoi(tokens[i]));
        }
        int ret = stk.top();
        stk.pop();
        return ret;
    }
};
