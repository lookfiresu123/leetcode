#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() && obstacleGrid[0].empty())
            return 0;
        auto sz_row = obstacleGrid.size();
        auto sz_col = obstacleGrid[0].size();
        vector<vector<int>> pathnum(sz_row, vector<int>(sz_col, 0));
        pathnum[0][0] = (obstacleGrid[0][0] == 1 ? 0 : 1);
        for (vector<vector<int>>::size_type i = 1 ; i < sz_row ; ++i)
            pathnum[i][0] = (obstacleGrid[i][0] == 1 ? 0 : pathnum[i-1][0]);
        for (vector<int>::size_type i = 1 ; i < sz_col ; ++i)
            pathnum[0][i] = (obstacleGrid[0][i] == 1 ? 0 : pathnum[0][i-1]);
        for (vector<vector<int>>::size_type i = 1 ; i < sz_row ; ++i)
            for (vector<int>::size_type j = 1 ; j < sz_col ; ++j)
                pathnum[i][j] = (obstacleGrid[i][j] == 1 ? 0 : (pathnum[i-1][j] + pathnum[i][j-1]));
        return pathnum[sz_row-1][sz_col-1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{1}};
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}

