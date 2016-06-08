#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    // it takes O(n) time
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        if (s.size() == 1)
            return s;
        // @start_pos : the start position of the longest palindrome substring
        // @max_len : the length of the longest palindrome substring
        int start_pos = 0, max_len = 1;
        for (int i = 0 ; i < s.size() ; ) {
            if (s.size() - i <= max_len / 2)
                break;
            int j = i, k = i;
            while (k < s.size()-1 && s[k+1] == s[k])
                ++k;       // skip duplicate characters, because duplicate characters must be palindrome
            i = k + 1;     // update i for next step
            while (k < s.size()-1 && j > 0 && s[k+1] == s[j-1]) {  // Bidirectionally Expand
                ++k;
                --j;
            }
            int new_len = k - j + 1;
            if (new_len > max_len) {   // update start_pos and max_len
                start_pos = j;
                max_len = new_len;
            }
        }
        return s.substr(start_pos, max_len);  // get the palindrome substring
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
