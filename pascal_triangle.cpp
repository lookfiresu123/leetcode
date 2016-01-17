#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> add_digits(int level, vector<int> &previous) {
        vector<int> result;
        if (level == 0)     // 第一层
            result.push_back(1);
        else if (level == 1) {  // 第二层
            result.push_back(1);
            result.push_back(1);
        } else {    // 其它
            result.push_back(1);
            for (int i = 1 ; i < level ; ++i)
                result.push_back(previous[i-1] + previous[i]);
            result.push_back(1);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> previous, current;
        if (numRows == 0)
            return result;
        else {
            for (int i = 0 ; i < numRows ; ++i) {
                current = add_digits(i, previous);
                result.push_back(current);
                previous = current;
            }
            return result;
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> vec = sol.generate(5);
    cout << (vec.empty() ? "true" : "false") << endl;
    return 0;
}
