#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.size()+num2.size(), '0');
        int sz1 = static_cast<int>(num1.size()-1);
        int sz2 = static_cast<int>(num2.size()-1);
        int carry = 0, temp, i, j;
        for (i = sz1 ; i >= 0 ; --i) {
            carry = 0;
            for (j = sz2 ; j >= 0 ; --j) {
                temp = (ret[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
                ret[i+j+1] = temp % 10 + '0';
                carry = temp / 10;
            }
            ret[i] += carry;
            // ret[i] = temp % 10 + '0';
            // carry = temp / 10;
        }
        auto iter = find_if(ret.begin(), ret.end(), [](char c){ return c != '0'; });
        string result(iter, ret.end());
        if (result.empty())
            result = "0";
        return result;
    }
};

int main() {
    string s1 = "123";
    string s2 = "456";
    Solution sol;
    cout << "ret = " << sol.multiply(s1, s2) << endl;
    return 0;
}
