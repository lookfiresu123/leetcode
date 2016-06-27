#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream input(path);
        string word, ret = "/";
        vector<string> vec;
        deque<string> dq;

        while (getline(input, word, '/'))
            if (!word.empty() && word != ".")
                vec.push_back(word);
        for (int i = 0 ; i < vec.size() ; ++i) {
            if (vec[i] != "..")
                dq.push_back(vec[i]);
            else if (!dq.empty())
                dq.pop_back();
        }
        while (!dq.empty()) {
            ret.append(dq.front() + "/");
            dq.pop_front();
            if (dq.empty())
                ret.pop_back();
        }
        return ret;
    }
};

int main() {
    string s = "///";
    Solution sol;
    cout << sol.simplifyPath(s) << endl;
    return 0;
}
