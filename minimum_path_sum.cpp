#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int min(int i, int j) { return i < j ? i : j; }

    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int>>::size_type sz_row = grid.size();
        vector<int>::size_type sz_col = grid[0].size();
        vector<vector<int>> sum = grid;
        sum[0][0] = grid[0][0];
        for (vector<vector<int>>::size_type i = 1 ; i < sz_row ; ++i)
            sum[i][0] = sum[i-1][0] + grid[i][0];
        for (vector<int>::size_type i = 1 ; i < sz_col ; ++i)
            sum[0][i] = sum[0][i-1] + grid[0][i];
        for (vector<vector<int>>::size_type i = 1 ; i < sz_row ; ++i)
            for (vector<int>::size_type j = 1 ; j < sz_col ; ++j)
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
        return sum[sz_row-1][sz_col-1];
    }
};

int main() {
    vector<vector<int>> grid = {{2,4},{3,6}};
    Solution sol;
    cout << sol.minPathSum(grid) << endl;
    return 0;
}
