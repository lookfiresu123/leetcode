#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

class Exception_1 {};
class Exception_2 {};

// 大数相加算法
class Solution {
private:
    const string str_store = "0123456789abcdefghijklmnopqrstuvwxyz";
public:
    // @str1：加数
    // @str2：被加数
    // @ary：进制
    string big_add(string &str1, string &str2, int ary) {
        const string str_pool = str_store;
        string ret;
        deque<int> dq1, dq2, dq_ret;
        // 检查str1和str2的正确性
        try {
            if (find_if(str1.begin(), str1.end(), [](char &c){ return isalpha(c) || isdigit(c); }) == str1.end() ||
                    find_if(str2.begin(), str2.end(), [](char &c){ return isalpha(c) || isdigit(c); }) == str2.end())
                throw Exception_1();
            else if (find_if(str1.begin(), str1.end(), [&str_pool, ary](char &c){ return tolower(c) > *(str_pool.begin()+ary-1); }) != str1.end() ||
                    find_if(str2.begin(), str2.end(), [&str_pool, ary](char &c){ return tolower(c) > *(str_pool.begin()+ary-1); }) != str2.end())
                throw Exception_2();
        } catch (Exception_1) {
            cout << "input only alpha or digit permit !" << endl;
            exit(0);
        } catch (Exception_2) {
            cout << "input out of range" << endl;
            exit(0);
        }

        // 大数计算
        for_each(str1.begin(), str1.end(), [&dq1](char &c)->void{ if (isalpha(c)) dq1.push_back(tolower(c)-'a'+10); else dq1.push_back(c-'0'); });
        for_each(str2.begin(), str2.end(), [&dq2](char &c)->void{ if (isalpha(c)) dq2.push_back(tolower(c)-'a'+10); else dq2.push_back(c-'0'); });
        int carry = 0;      // 进位数
        while (dq1.size() != dq2.size()) {
            if (dq1.size() < dq2.size())
                dq1.push_front(0);
            else
                dq2.push_front(0);
        }
        for (auto it1 = dq1.rbegin(), it2 = dq2.rbegin() ; it1 != dq1.rend() ; ++it1, ++it2) {
            int temp = *it1 + *it2 + carry;
            dq_ret.push_front(temp % ary);
            carry = temp / ary;
        }
        if (carry)
            dq_ret.push_front(carry);
        for_each(dq_ret.begin(), dq_ret.end(), [&ret, &str_pool](int x){ ret.push_back(str_pool[static_cast<string::size_type>(x)]); });
        return ret;
    }
};

int main() {
    string str1, str2;
    int ary;
    cin >> str1 >> str2 >> ary;
    cin.sync();
    cin.clear();
    Solution sol;
    cout << sol.big_add(str1, str2, ary) << endl;
    return 0;
}
