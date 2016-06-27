#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, n = s.size()+1;
        vector<int> vec(n, 0);
        vector<int> prev_pos(255, -1);
        for (int i = 1, start = -1 ; i < n ; ++i) {
            if (prev_pos[ s[i-1] ] >= start)
                start = prev_pos[ s[i-1] ] + 1;
            vec[i] = (i - 1) - start + 1;
            prev_pos[ s[i-1] ] = i - 1;
            max = vec[i] > max ? vec[i] : max;
        }
        return max;
    }
};

int main() {
    string s = "abcdbae";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
