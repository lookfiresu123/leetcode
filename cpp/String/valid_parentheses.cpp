#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    stack<char> stk;
public:
    bool isValid(string s) {
        char temp;
        bool flag_1, flag_2, flag_3;
        for (char c : s) {
            if (stk.empty())
                stk.push(c);
            else {
                temp = stk.top();
                flag_1 = ((temp == '[' && c ==']') || (temp == ']' && c == '['));
                flag_2 = ((temp == '{' && c =='}') || (temp == '}' && c == '{'));
                flag_3 = ((temp == '(' && c ==')') || (temp == ')' && c == '('));
                if (flag_1 || flag_2 || flag_3)
                    stk.pop();
                else
                    stk.push(c);
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};

int main () {
    string s = "()[]{}";
    Solution sol;
    cout << (sol.isValid(s) ? "true" : "false") << endl;
    return 0;
}
