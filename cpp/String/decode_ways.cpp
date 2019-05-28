#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isvalid_one(char c) {
        return c >= '1' && c <= '9';
    }

    bool isvalid_two(string str) {
        if (str[0] == '0')
            return false;
        return stoi(str) >= 1 && stoi(str) <= 26;
    }

    int numDecodings(string s) {
        vector<int> p(s.size()+1, 0);     // p[i]表示在位置为i的地方有多少种方法，其中p[0]表示s为空
        int sz = p.size();
        if (sz <= 1)    // 当s为空时，返回0种
            return 0;
        p[0] = 1;
        p[1] = isvalid_one(s[0]) ? 1 : 0;
        for (int i = 2 ; i < sz ; ++i) {
            p[i] += isvalid_one(s[i-1]) ? p[i-1] : 0;   // p[i]表示s[0:i-1]数组的总方法数
            p[i] += isvalid_two(s.substr(i-2, 2)) ? p[i-2] : 0;
        }
        return p[sz-1];
    }
};

int main() {
    string s = "10";
    Solution sol;
    cout << sol.numDecodings(s) << endl;
    return 0;
}
