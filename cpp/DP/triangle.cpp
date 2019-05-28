#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minpath = INT_MAX;
        if (triangle.empty() || triangle[0].empty())
            return 0;
        int len = triangle.size();
        vector<vector<int>> path(len, vector<int>(len));
        path[0][0] = triangle[0][0];
        for (int i = 1 ; i < len ; ++i) {
            path[i][0] = path[i-1][0] + triangle[i][0];
            for (int j = 1 ; j < i ; ++j)
                path[i][j] = min(path[i-1][j-1], path[i-1][j]) + triangle[i][j];
            path[i][i] = path[i-1][i-1] + triangle[i][i];
        }
        for (int j = 0 ; j < len ; ++j)
            if (minpath > path[len-1][j])
                minpath = path[len-1][j];
        return minpath;
    }
};
