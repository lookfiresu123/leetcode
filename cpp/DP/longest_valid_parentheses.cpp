#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2)
            return 0;

        vector<int> vec(s.length()+1, 0);     // 其中vec[i]表示以s[i]结尾的子串有多长

        for (int i = 2 ; i < vec.size() ; ++i) {
            if (s[i-2] == '(' && s[i-1] == '(' || s[i-2] == ')' && s[i-1] == '(')
                vec[i] = 0;
            else if (s[i-2] == '(' && s[i-1] == ')')
                vec[i] = vec[i-2] + 2;
            else {
                if (i-2-vec[i-1] < 0)
                    vec[i] = 0;
                else if (s[i-2-vec[i-1]] == '(')
                    vec[i] = 2 + vec[i-1] + vec[i-2-vec[i-1]];
            }
        }

        // 找到vec[i]中的最大值
        int max = 0;
        for (int i = 0 ; i < vec.size() ; ++i)
            max = max < vec[i] ? vec[i] : max;

        return max;
    }
};
