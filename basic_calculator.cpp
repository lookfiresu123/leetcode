#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int getPriority(char operator_char) {
        if (operator_char == '+' || operator_char == '-')
            return 1;
        else
            return 2;
    }

    bool is_operator_char(char &c) {
        if (c == '+' || c == '-' || c == '*' || c == '/')
            return true;
        else
            return false;
    }

    bool is_operator_str(string &s) {
        if (s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        else
            return false;
    }

    vector<string> infix_to_postfix(string infix) {
        // delete ''
        for (string::iterator it = infix.begin() ; it != infix.end() ; ) {
            if (*it == ' ')
                it = infix.erase(it);
            else
                ++it;
        }
        // get postfix strings
        vector<string> postfix;
        stack<char> operator_chars;
        string::iterator start = infix.begin(), finish = start;
        while (finish != infix.end()) {
            if (!is_operator_char(*finish))
                ++finish;
            else {
                postfix.push_back(string(start, finish));
                while (!operator_chars.empty() && getPriority(*finish) <= getPriority(operator_chars.top())) {
                    postfix.push_back(string(1, operator_chars.top()));
                    operator_chars.pop();
                }
                operator_chars.push(*finish);
                start = finish + 1;
                finish = start;
            }
        }
        postfix.push_back(string(start, finish));
        while (!operator_chars.empty()) {
            postfix.push_back(string(1, operator_chars.top()));
            operator_chars.pop();
        }
        return postfix;
    }

    int calculate(string s) {
        vector<string> postfix = infix_to_postfix(s);
        stack<int> operands;
        stack<string> operator_strs;
        for (int i = 0 ; i < postfix.size() ; ++i) {
            if (!is_operator_str(postfix[i]))
                operands.push(stoi(postfix[i]));
            else {
                int op1 = operands.top();
                operands.pop();
                int op2 = operands.top();
                operands.pop();
                int ret;
                if (postfix[i] == "+")
                    ret = op2 + op1;
                else if (postfix[i] == "-")
                    ret = op2 - op1;
                else if (postfix[i] == "*")
                    ret = op2 * op1;
                else if (postfix[i] == "/")
                    ret = op2 / op1;
                operands.push(ret);
            }
        }
        return operands.top();
    }
};

int main() {
    string s = "0";
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}
