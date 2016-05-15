#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string common_prefix;
        if (strs.empty())
            return common_prefix;
        common_prefix = strs[0];
        for (int i = 1 ; i < strs.size() ; ++i) {
            string::iterator it1, it2;
            for (it1 = common_prefix.begin(), it2 = strs[i].begin() ; it1 != common_prefix.end() && it2 != strs[i].end() ; ++it1, ++it2)
                if (*it1 != *it2)
                    break;
            common_prefix.erase(it1, common_prefix.end());
        }
        return common_prefix;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("hello world");
    strs.push_back("hello baby");
    strs.push_back("help me");
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
