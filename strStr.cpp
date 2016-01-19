#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;
        else {
            for (auto iter = haystack.begin() ; iter <= haystack.end() - needle.size() ; ++iter) {
                if (string(iter, iter + needle.size()) == needle)
                    return static_cast<int>(iter - haystack.begin());
            }
            return -1;
        }
    }
};

int main () {
    string haystack = "llow";
    string needle = "llow";
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}
