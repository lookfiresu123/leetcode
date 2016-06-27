#include <cctype>
#include <string>
#include <iostream>

using namespace std;

// 一个有效的数字需要满足以下4个条件
// 1. 跳过开头的空格键（可能没有）
// 2. 检查第一个非空格符是否为有效的符号位（-、+、无），
// 跳过符号位后计数digit和'.'的个数（直到遇到非这两类数为止），其中digit至少含有一个，
// 而'.'最多含有一个
// 3. 检查指数符号是否有效，若含有'e'，则尾后至少包含一个digit
// 4. 跳过尾后的空格

class Solution {
public:
    bool isNumber(string s) {
        string::size_type i = 0;
        // 跳过开头的空格键
        for ( ; s[i] == ' ' ; ++i )
            ;
        // 之后检查并跳过符号位
        if (s[i] == '+' || s[i] == '-')
            ++i;

        // 计数digit和'.'的个数
        int cnt_pointer, cnt_digit;
        for (cnt_digit = 0, cnt_pointer = 0 ; isdigit(s[i]) || s[i] == '.' ; ++i)
            s[i] == '.' ? ++cnt_pointer : ++cnt_digit;
        if (cnt_pointer > 1 || cnt_digit < 1)
            return false;

        // 检查'e'是否存在，若存在则进行相应的处理（在除去符号位之后至少需要包含一个digit）
        if (s[i] == 'e') {
            ++i;
            if (s[i] == '+' || s[i] == '-')
                ++i;
            int cnt_digit;
            for (cnt_digit = 0 ; isdigit(s[i]) ; ++i)
                ++cnt_digit;
            if (cnt_digit < 1)
                return false;
        }

        // 跳过之后的空格键
        for ( ; s[i] == ' ' ; ++i)
            ;

        // 判断是否到了字符串的尽头
        return i == s.size();
    }
};

int main() {
    string s = "2e0";
    Solution sol;
    bool ret = sol.isNumber(s);
    cout << (ret ? "true" : "false") << endl;
    return 0;
}
