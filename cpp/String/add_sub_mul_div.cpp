#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:
    string Add(string s1, string s2) {
        string res;
        if ((s1.empty() || s2.empty()) || (s1 == "-" || s2 == "-"))
            cout << "Input invalid!" << endl;
        if (s1[0] != '-' && s2[0] != '-') {         // 处理正数加正数
            res = AddPP(s1, s2);
        } else if (s1[0] == '-' && s2[0] == ' ') {  // 处理负数加负数
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            res = AddPP(s1, s2);
            res.insert(res.begin(), '-');
        } else if (s1[0] == '-') {                  // 处理负数加正数
            s1.erase(s1.begin());
            res = SubPP(s2, s1);
        } else if (s2[0] == '-') {                  // 处理正数加负数
            s2.erase(s2.begin());
            res = SubPP(s1, s2);
        }
        return res;
    }

    string Sub(string &s1, string &s2) {
        string res;
        if ((s1.empty() || s2.empty()) || (s1 == "-" || s2 == "-"))
            cout << "Input invalid!" << endl;
        if (s1[0] != '-' && s2[0] != '-') {         // 处理正数减正数
            res = SubPP(s1, s2);
        } else if (s1[0] == '-' && s2[0] == ' ') {  // 处理负数减负数
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            res = SubPP(s2, s1);
        } else if (s1[0] == '-') {                  // 处理负数减正数
            s1.erase(s1.begin());
            res = AddPP(s1, s2);
            res.insert(res.begin(), '-');
        } else if (s2[0] == '-') {                  // 处理正数减负数
            s2.erase(s2.begin());
            res = AddPP(s1, s2);
        }
        return res;
    }

    string Mul(string &s1, string &s2) {
        string res;
        if ((s1.empty() || s2.empty()) || (s1 == "-" || s2 == "-"))
            cout << "Input invalid!" << endl;
        if (s1[0] != '-' && s2[0] != '-') {         // 处理正数乘正数
            res = MulPP(s1, s2);
        } else if (s1[0] == '-' && s2[0] == ' ') {  // 处理负数乘负数
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            res = MulPP(s1, s2);
        } else if (s1[0] == '-') {                  // 处理负数乘正数
            s1.erase(s1.begin());
            res = MulPP(s1, s2);
            res.insert(res.begin(), '-');
        } else if (s2[0] == '-') {                  // 处理正数乘负数
            s2.erase(s2.begin());
            res = MulPP(s1, s2);
            res.insert(res.begin(), '-');
        }
        return res;
    }

    pair<string, string> Div(string &s1, string &s2) {
        pair<string, string> ret;
        if ((s1.empty() || s2.empty()) || (s1 == "-" || s2 == "-"))
            cout << "Input invalid!" << endl;
        if (s1[0] != '-' && s2[0] != '-') {         // 处理正数除以正数
            ret = DivPP(s1, s2);
        } else if (s1[0] == '-' && s2[0] == ' ') {  // 处理负数除以负数
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            ret = DivPP(s1, s2);
        } else if (s1[0] == '-') {                  // 处理负数除以正数
            s1.erase(s1.begin());
            ret = DivPP(s1, s2);
            ret.first.insert(ret.first.begin(), '-');
        } else if (s2[0] == '-') {                  // 处理正数除以负数
            s2.erase(s2.begin());
            ret = DivPP(s1, s2);
            ret.first.insert(ret.first.begin(), '-');
        }
        return ret;
    }
private:
    // 正数加正数
    string AddPP(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        int len = len1 < len2 ? len2 : len1;
        // 填充
        s1 = string(len - len1, '0').append(s1);
        s2 = string(len - len2, '0').append(s2);
        // 计算
        string res(len + 1, '0');
        int carry = 0, t1, t2, t;
        for (int i = len ; i > 0 ; --i) {
            t1 = s1[i-1] - '0';
            t2 = s2[i-1] - '0';
            t = (res[i] - '0') + t1 + t2 + carry;
            res[i] += t % 10;
            carry = t / 10;
        }
        res[0] += carry;
        // 去掉多余的0
        while (*res.begin() == '0')
            res.erase(res.begin());
        return res;
    }

    // 正数减正数
    string SubPP(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        int len = len1 < len2 ? len2 : len1;
        // 填充
        s1 = string(len - len1, '0').append(s1);
        s2 = string(len - len2, '0').append(s2);
        // 计算
        string res(len, '0');
        if (s1 == s2)
            return "0";
        else if (s1 < s2) {
            res = SubPP(s2, s1);
            res.insert(res.begin(), '-');
        } else {
            int t1, t2;
            for (int i = len-1 ; i >= 0 ; --i) {
                t1 = s1[i] - '0';
                t2 = s2[i] - '0';
                if (t1 < t2) {
                    int j;
                    for (j = i-1 ; j >= 0 && s1[j] == '0' ; --j) {
                        s1[j] = '9';
                    }
                    --s1[j];
                    t1 += 10;
                }
                res[i] += t1 - t2;
            }
            // 去掉多余的0
            while (*res.begin() == '0')
                res.erase(res.begin());
        }
        return res;
    }

    // 正数乘正数
    string MulPP(string s1, string s2) {
        string res(s1.size()+s2.size(), '0');
        int sz1 = static_cast<int>(s1.size()-1);
        int sz2 = static_cast<int>(s2.size()-1);
        int carry = 0, temp, i, j;
        for (i = sz1 ; i >= 0 ; --i) {
            carry = 0;
            for (j = sz2 ; j >= 0 ; --j) {
                temp = (res[i+j+1]-'0') + (s1[i]-'0') * (s2[j]-'0') + carry;
                res[i+j+1] = temp % 10 + '0';
                carry = temp / 10;
            }
            res[i] += carry;
        }
        // 去掉多余的0
        while (*res.begin() == '0')
            res.erase(res.begin());
        return res;
    }

    // 正数除正数
    pair<string, string> DivPP(string s1, string s2) {
        pair<string, string> ret;
        DivPP_helper(s1, s2, ret);
        return ret;
    }

    void DivPP_helper(string s1, string s2, pair<string, string> &ret) {
        if (s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2)) {
            if (ret.first.empty())
                ret.first.append("0");
            ret.second.append(s1);
        } else {
            int len2 = s2.length(), sz = len2;
            int len1 = s1.length();
            string tmp = s1.substr(0, sz);
            if (tmp < s2)
                tmp = s1.substr(0, ++sz);
            char c;
            for (c = '1' ; c <= '9' ; ++c) {
                string s(1, c);
                string t = MulPP(s2, s);
                if (tmp.length() < t.length() || (tmp.length() == t.length() && tmp < t))
                    break;
            }
            --c;
            ret.first.append(string(1, c));
            string s = MulPP(s2, string(1, c));
            s.append(string(len1-sz, '0'));
            s1 = SubPP(s1, s);
            DivPP_helper(s1, s2, ret);
        }
    }
};

int main () {
    Calculator cal;
    while (true) {
        string s1, s2;
        int index;
        cout << "Input two digits!" << endl;
        cin >> s1 >> s2;
        cout << "Input 1 for Add, 2 for Sub, 3 for Mul, 4 for Div, 0 for break!" << endl;
        cin >> index;
        string res;
        pair<string, string> ret;
        switch (index) {
            case 1:
                res = cal.Add(s1, s2);
                cout << res << endl;
                break;
            case 2:
                res = cal.Sub(s1, s2);
                cout << res << endl;
                break;
            case 3:
                res = cal.Mul(s1, s2);
                cout << res << endl;
                break;
            case 4:
                ret = cal.Div(s1, s2);
                cout << "商：" << ret.first << ", 余数：" << ret.second  << endl;
                break;
            case 0:
                return 0;
            default:
                cout << "Input invalid!" << endl;
                break;
        }
    }
    return 0;
}
