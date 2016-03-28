#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        auto sz_row = matrix.size()-1;
        auto sz_col = matrix.size()-1;
        for (vector<vector<int>>::size_type i = 0 ; i <= sz_row ; ++i)
            for (vector<int>::size_type j = 0 ; j <= sz_col ; ++j)
                matrix[j][sz_col-static_cast<vector<int>::size_type>(i)] = temp[i][j];
    }
};
