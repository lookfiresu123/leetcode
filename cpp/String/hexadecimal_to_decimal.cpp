#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getValue(string &s) {
        // 去掉"0x"
        string s1 = s.substr(2);
        string ret;
        for (auto ch : s1)
            ret = Calculate(ret, 16, ch);
        return ret;
    }
private:
    string Calculate(string &vec, int base, char ch) {
        if (vec.empty()) {
            if (ch >= 'A' && ch <= 'F')
                return to_string(ch-'A'+10);
            return to_string(ch-'0');
        }
        string s = to_string(base);
        int sz1 = vec.length(), sz2 = s.length();
        int sz = sz1 + sz2;
        string ret(sz, '0');
        // a[i] * b[j] -> c[i+j+1]
        int tmp1, tmp2, tmp, carry;
        for (int i = sz1-1 ; i >= 0 ; --i) {
            carry = 0;
            for (int j = sz2-1 ; j >= 0 ; --j) {
                tmp1 = vec[i] - '0';
                tmp2 = s[j] - '0';
                tmp = tmp1 * tmp2;
                int per = ret[i+j+1] - '0';
                per += (tmp + carry);
                ret[i+j+1] = per % 10 + '0';
                carry = per / 10;
            }
            ret[i] = carry + '0';
        }

        // ret = ret + ch
        if (ch >= 'A' && ch <= 'F')
            carry = ch-'A'+10;
        else
            carry = ch-'0';

        for (int i = sz-1 ; i >= 0 ; --i) {
            int tmp1 = ret[i]-'0';
            ret[i] = (tmp1 + carry) % 10 + '0';
            carry = (tmp1 + carry) / 10;
            if (carry == 0)	break;
        }

        if (carry != 0)
            ret.insert(ret.begin(), carry+'0');

        // 去掉开头多余的'0'
        int start;
        for (start = 0 ; start < sz ; ++start)
            if (ret[start] != '0')
            	break;
        ret = ret.substr(start);
        return ret;
    }
};

int main() {
    Solution sol;
    string s;
    vector<string> ret;
    while (cin >> s)
        ret.push_back(sol.getValue(s));
    for (auto str : ret)
        cout << str << endl;
    return 0;
}
