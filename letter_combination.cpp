#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vec(8);  // 2~9
        vector<string> ret;
        string copy_digits;
        copy_digits.reserve(digits.length());
        for (char &c : digits)
            if (c >= '2' && c <= '9')
                copy_digits.push_back(c);
        if (copy_digits.empty() || copy_digits.length() < digits.length())
            return ret;
        initialize(vec);
        string tmp;
        letterCombinations_helper(ret, vec, tmp, copy_digits, 0);
        return ret;
    }
private:
    void letterCombinations_helper(vector<string> &ret, vector<string> &vec, string &tmp, string &copy_digits, string::size_type index) {
        if (copy_digits.length() <= index)
            ret.push_back(tmp);
        else {
            string str = vec[copy_digits[index] - '2'];
            for (char &c : str) {
                tmp.push_back(c);
                letterCombinations_helper(ret, vec, tmp, copy_digits, index+1);
                tmp.pop_back();
            }
        }
    }

    void initialize(vector<string> &vec) {
        vec[0].append("abc");
        vec[1].append("def");
        vec[2].append("ghi");
        vec[3].append("jkl");
        vec[4].append("mno");
        vec[5].append("pqrs");
        vec[6].append("tuv");
        vec[7].append("wxyz");
    }
};

void print(vector<string> &ret) {
    for (string &s : ret)
        cout << s << " ";
    cout << endl;
}

int main() {
    Solution sol;
    string digits = "2314";
    vector<string> ret = sol.letterCombinations(digits);
    print(ret);
    return 0;
}
