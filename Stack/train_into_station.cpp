#include <iostream>
#include <set>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    set<string> getValue(string s) {
        set<string> ret;
        getValue_helper(ret, s, string(), stack<char>(), 0);
        return ret;
    }
private:
    void getValue_helper(set<string> &ret, string &s, string tmp, stack<char> stk, int index) {
    	if (index == s.length()) {      // 没有车要入栈了
            while (!stk.empty()) {
                tmp.push_back(stk.top());
                stk.pop();
            }
            ret.insert(tmp);
        } else {                        // 当第index辆车要选择是否入栈时
            if (stk.empty()) {  // 若栈为空
                // s[index]入栈的情况
                stk.push(s[index]);
                getValue_helper(ret, s, tmp, stk, index+1);
                // 还原状态
                stk.pop();
                // s[index]不入栈的情况
                tmp.push_back(s[index]);
                getValue_helper(ret, s, tmp, stk, index+1);
            } else {

                // stk中没有车要出栈的情况
                // s[index]入栈的情况
                stk.push(s[index]);
                getValue_helper(ret, s, tmp, stk, index+1);
                // 还原状态
                stk.pop();
                // s[index]不入栈的情况
                tmp.push_back(s[index]);
                getValue_helper(ret, s, tmp, stk, index+1);

                tmp.pop_back();
                // stk中有车先出栈的情况
                while (!stk.empty()) {
                    tmp.push_back(stk.top());
                    stk.pop();
                    // s[index]入栈的情况
                    stk.push(s[index]);
                    getValue_helper(ret, s, tmp, stk, index+1);
                    // 还原状态
                    stk.pop();
                    // s[index]不入栈的情况
                    tmp.push_back(s[index]);
                    getValue_helper(ret, s, tmp, stk, index+1);
                    // 还原状态
                    tmp.pop_back();
                }
	        }
        }
    }
};

int main() {
    int n, t;
    Solution sol;
    set<string> ret;
    while (cin >> n) {
        string s;
        while (n-- > 0) {
            cin >> t;
            s.append(to_string(t));
        }
        ret = sol.getValue(s);
        for (auto it = ret.begin() ; it != ret.end() ; ++it) {
            string s;
            for (auto c : *it)
                s = s + c + ' ';
            s.pop_back();
            cout << s << endl;
        }
    }
    return 0;
}
