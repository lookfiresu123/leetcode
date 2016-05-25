#include <vector>
#include <iostream>
#include <string>

using namespace std;

// prefix = vec[0...i], suffix = vec[j...n-1]
// i = -1 ~ n-1 , j = n ~ 0 => i = 0 ~ n, j = n ~ 0
class Solution {
public:
    int maxXor(vector<int> &vec) {
        int n = vec.size();
        // use heap instead of stack, because the max limit of stack is 8M and the test data maybe 256 MB
        vector<vector<int> > *max_panel_ptr = new vector<vector<int> >(n+1, vector<int>(n+1, 0));
        int max = 0;
        for (int i = 1 ; i < n+1 ; ++i) {
            for (int j = n-1 ; j >= 0 ; --j) {
                (*max_panel_ptr)[i][j] = getMax((*max_panel_ptr)[i-1][j] ^ vec[i-1], (*max_panel_ptr)[i][j+1] ^ vec[j]);
                max = getMax(max, (*max_panel_ptr)[i][j]);
            }
        }
        delete max_panel_ptr;
        return max;
    }
private:
    int getMax(int x, int y) {
        return x > y ? x : y;
    }
};

int main() {
    int sz, tmp;
    cin >> sz;
    vector<int> vec;
    vec.reserve(sz);
    for (int i = 0 ; i < sz; ++i) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    Solution sol;
    cout << sol.maxXor(vec) << endl;
    return 0;
}
