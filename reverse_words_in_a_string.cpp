#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // reverse s
        reverse(s, 0, s.length()-1);

        // remove the head space
        string::iterator start = s.begin(), end = start;
        while (end != s.end() && *end == ' ')
            ++end;
        s.erase(start, end);
        // remove the tail space
        if (!s.empty()) {
            end = s.end(), start = end - 1;
            while (start != s.begin() && *start == ' ')
                --start;
            s.erase(++start, s.end());
        }

        // remove extra space
        for (string::iterator it = s.begin() ; it != s.end() ; ) {
            while (it != s.end() && *it != ' ')
                ++it;
            if (it != s.end()) {
                ++it;
                string::iterator copy_it = it;
                while (it != s.end() && *it == ' ')
                    ++it;
                it = s.erase(copy_it, it);
            }
        }

        // process string s
        int pos = 0, copy_pos;
        while (true) {
            copy_pos = pos;
            pos = s.find_first_of(' ', pos);
            if (pos != string::npos) {
                reverse(s, copy_pos, pos-1);
                ++pos;
            } else {
                reverse(s, copy_pos, s.length()-1);
                break;
            }
        }
    }
private:
    void reverse(string &s, int i, int j) {
        while (i <= j)
            swap(s, i++, j--);
    }

    void swap(string &s, int i, int j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
};

int main() {
    string s = "";
    cout << s << endl;
    Solution sol;
    sol.reverseWords(s);
    cout << s << endl;
    return 0;
}
