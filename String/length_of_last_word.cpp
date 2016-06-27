#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length();
        while (i > 0 && s[--i] == ' ')
            s.pop_back();
        stringstream input(s);
        string word;
        while (getline(input, word, ' ')) ;
        return word.length();
    }
};

int main() {
    string s = "hello world";
    Solution sol;
    cout << sol.lengthOfLastWord(s) << endl;
    return 0;
}
