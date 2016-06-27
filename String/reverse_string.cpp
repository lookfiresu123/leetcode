#include <string>

using namespace std;

class Solution {
public:
    void swap(string &s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    string reverseString(string s) {
        for (int i = 0, j = s.size()-1 ; i <= j ; ++i, --j)
            swap(s, i, j);
        return s;
    }
};
