#include <vector>
#include <iostream>
#include <cctype>
#include <locale>
#include <iterator>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> vec;
        for (auto c : s) {
            if (isdigit(c))
                vec.push_back(c);
            else if (isalpha(c))
                vec.push_back(tolower(c));
        }
        vector<char>::iterator left, right;
        if (vec.empty())
            return true;
        for (left = vec.begin(), right = vec.end()-1 ; left <= right ; ++left, --right) {
            if (*left != *right)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = "a";
    // cout << (sol.isPalindrome(s1) ? "true" : "false") << endl;
    // cout << (sol.isPalindrome(s2) ? "true" : "false") << endl;
    cout << (sol.isPalindrome(s3) ? "true" : "false") << endl;
    return 0;
}
