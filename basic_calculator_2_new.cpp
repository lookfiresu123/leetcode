#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        int len = s.length();
        stack<int> stk;
        int operand = 0;
        char operator_char = '+';
        int ret = 0;
        for (int i = 0 ; i < len ; ++i) {
            if (isdigit(s[i]))
                operand = operand * 10 + s[i] - '0';
            if (!isdigit(s[i]) && s[i] != ' ' || i == len-1) {
                if (operator_char == '+')
                    stk.push(operand);
                else if (operator_char == '-')
                    stk.push(0 - operand);
                else if (operator_char == '*') {
                    operand = stk.top() * operand;
                    stk.pop();
                    stk.push(operand);
                }
                else {
                    operand = stk.top() / operand;
                    stk.pop();
                    stk.push(operand);
                }
                operator_char = s[i];
                operand = 0;
            }
        }
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
        return ret;
    }
};

int main() {
    string s = "- 1+2 *3 -4/ 4 ";
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}
