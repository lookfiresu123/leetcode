#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return string();
        string seq_s = s, rev_s = s;
        reverseString(rev_s);
        string tmp_s = s + '#' + rev_s;
        int sz = tmp_s.length();
        vector<int> next = getNext(tmp_s);
        return rev_s.substr(0, s.size() - next[sz-1]) + s;
    }
private:
    void reverseString(string &s) {
        for (int i = 0, j = s.length()-1 ; i < j ; ++i, --j)
            swap(s, i, j);
    }
    void swap(string &s, int i, int j) {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    vector<int> getNext(string &s) {
        int sz = s.length();
        vector<int> next(sz, 0);
        for (int i = 1, j = 0 ; i < sz ; ) {
            if (s[i] == s[j])
                next[i++] = ++j;
            else if (j)
                j = next[j-1];
            else
                next[i++] = 0;
        }
        return next;
    }
};
