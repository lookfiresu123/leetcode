#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> getValue(string &s) {
        vector<string> ret;

        // 计算1~26的斐波那契数，因为字符种类为1~26
        vector<bool> fds(27, false);
        int min = 1, max = 2, tmp;
        fds[min] = fds[max] = true;
        while (true) {
            tmp = max;
            max += min;
            if (max > 26)	break;
            fds[max] = true;
            min = tmp;
        }
        // 计数每个字母的个数
        int sz = s.length();
        set<string> strset;				// {result of string}
        for (int i = 0 ; i < sz ; ++i) {
            vector<int> chvec(26, 0);	// {a, ..., z}
            int cnt = 0;				// acount of different characters
            for (int j = i ; j < sz ; ++j) {
                if (chvec[s[j]-'a'] == 0) {
                    chvec[s[j]-'a'] = 1;
                    cnt++;
                }
            	if (fds[cnt])
                   	strset.insert(s.substr(i, j-i+1));
            }
        }
        for (auto it = strset.begin() ; it != strset.end() ; ++it)
            ret.push_back(*it);

        return ret;
    }
};

int main() {
    string s;
    vector<vector<string>> ret;
    Solution sol;
    while (cin >> s)
        ret.push_back(sol.getValue(s));
    for (auto vec : ret)
        for (auto str : vec)
        	cout << str << endl;
    return 0;
}
