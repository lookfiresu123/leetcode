#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            vector<int> ret;
            return ret;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret(m*n, 0);
        int col_step = n, row_step = m-1;
        int i = 0, j = -1, k = -1;
        while (true) {

            if (col_step <= 0)  break;
            for (int z = 0 ; z < col_step ; ++z)
                ret[++k] = matrix[i][++j];
            --col_step;

            if (row_step <= 0)  break;
            for (int z = 0 ; z < row_step ; ++z)
                ret[++k] = matrix[++i][j];
            --row_step;

            if (col_step <= 0)  break;
            for (int z = 0 ; z < col_step ; ++z)
                ret[++k] = matrix[i][--j];
            --col_step;

            if (row_step <= 0)  break;
            for (int z = 0 ; z < row_step ; ++z)
                ret[++k] = matrix[--i][j];
            --row_step;

        }
        return ret;
    }
};
