#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int getValueByKmp(const string &text, const string &needle) {
        int cnt = 0;
        int sz1 = text.length(), sz2 = needle.length();
        vector<int> next = getNext(needle);
        for (int i = 0, j = 0 ; i < sz1 ; ) {
            if (text[i] == needle[j])
                ++i, ++j;
            if (j == sz2) {
                ++cnt, j = next[j-1];
                continue;
            }
            if (i < sz1 && text[i] != needle[j]) {
                if (j)  j = next[j-1];
                else    ++i;
            }
        }
        return cnt;
    }
private:
    vector<int> getNext(const string &needle) {
        int sz = needle.length();
        vector<int> next(sz, 0);
        for (int i = 1, j = 0 ; i < sz ; ) {
            if (needle[i] == needle[j])
                next[i++] = ++j;
            else if (j)
                j = next[j-1];
            else
                next[i++] = 0;
        }
        return next;
    }
};

int main() {
    int N;
    cin >> N;
    Solution sol;
    vector<int> ret(N, 0);
    string text, needle;
    for (int i = 0 ; i < N ; ++i) {
        cin >> needle >> text;
        ret[i] = sol.getValueByKmp(text, needle);
    }
    for (int i = 0 ; i < N ; ++i)
        cout << ret[i] << endl;
    return 0;
}
