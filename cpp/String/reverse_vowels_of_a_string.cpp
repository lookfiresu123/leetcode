#include <string>

using namespace std;

class Solution {
public:
    bool isContain(char c) {
        bool b1 =  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        bool b2 =  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        return b1 || b2;
    }

    void swap(string &s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    string reverseVowels(string s) {
        if (s.empty())
            return s;
        int lo = 0, hi = s.size()-1;
        int i = lo-1, j = hi+1;
        while (true) {
            while (i < hi && !isContain(s[++i]));
            while (j > lo && !isContain(s[--j]));
            if (j <= i) break;
            swap(s, i, j);
        }
        return s;
    }
};
