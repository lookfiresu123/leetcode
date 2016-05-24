#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxXor(vector<int> &vec) {
        int n = vec.size();
        // prefix = vec[0...i], suffix = vec[j...n-1]
        // i = -1 ~ n-1 , j = n ~ 0 => i = 0 ~ n, j = n ~ 0
        vector<vector<int> > max_panel(n+1, vector<int>(n+1, 0));
        int max = 0;
        for (int i = 1 ; i < n+1 ; ++i) {
            for (int j = n-1 ; j >= 0 ; --j) {
                max_panel[i][j] = getMax(max_panel[i-1][j] ^ vec[i-1], max_panel[i][j+1] ^ vec[j]);
                max = getMax(max, max_panel[i][j]);
            }
        }
        return max;
    }
private:
    int getMax(int x, int y) {
        return x > y ? x : y;
    }
};

int main() {
    vector<int> vec;
    for (int i = 0 ; i < 3 ; ++i)
        vec.push_back(i);
    Solution sol;
    cout << sol.maxXor(vec) << endl;
    return 0;
}
