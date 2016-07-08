#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)   return true;
        if (s1.length() != s2.length()) return false;
        vector<int> vec(256, 0);
        int sz = s1.length();

        // make sure that any character of s1 and s2 has the same acount
        for (int i = 0 ; i < sz ; ++i)
            ++vec[s1[i]], --vec[s2[i]];
        for (int i = 0 ; i < 256 ; ++i)
            if (vec[i] != 0)
                return false;

        for (int i = 1 ; i < sz ; ++i)
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))
             || isScramble(s1.substr(0, i), s2.substr(sz-i)) && isScramble(s1.substr(i), s2.substr(0, sz-i)))
                return true;
        return false;

    }
};
