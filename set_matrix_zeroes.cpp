#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    void setZeroes_helper(vector<vector<int>> &matrix, vector<vector<int>>::size_type row_limit, vector<int>::size_type col_limit,
            vector<vector<int>>::size_type pos_row, vector<int>::size_type pos_col) {
        if (row_limit < pos_row || col_limit < pos_col)
            return ;
        setZeroes_helper(matrix, row_limit, col_limit, pos_row+1, pos_col);
        setZeroes_helper(matrix, row_limit, col_limit, pos_row, pos_col+1);
        if (matrix[pos_row][pos_col] == 0) {
            for (vector<vector<int>>::size_type i = pos_row ; i <= row_limit ; ++i)
                matrix[i][pos_col] = 0;
            for (vector<int>::size_type i = pos_col ; i <= col_limit ; ++i)
                matrix[pos_row][i] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return ;
        auto row_limit = matrix.size()-1;
        auto col_limit = matrix[0].size()-1;
        setZeroes_helper(matrix, row_limit, col_limit, 0, 0);
    }
};

void initialize(vector<vector<int>> &matrix, int m, int n) {
    srand(time(0));
    vector<int> temp(n, 0);
    for (int i = 0 ; i < m ; ++i) {
        generate(temp.begin(), temp.end(), [](){ return rand()%100; });
        matrix.push_back(temp);
    }
}

void print(vector<vector<int>> &matrix) {
    for (auto iter = matrix.begin() ; iter != matrix.end() ; ++iter) {
        for_each(iter->begin(), iter->end(), [](int x){ cout << x << " "; });
        cout << endl;
    }
}


int main() {
    vector<vector<int>> matrix;
    int m = 5, n = 4;                   // m行，n列
    initialize(matrix, m, n);
    cout << "matrix :" << endl;
    cout << "----------------" << endl;
    print(matrix);
    cout << "----------------" << endl;
    matrix[0][0] = 0;
    matrix[2][2] = 0;
    Solution sol;
    sol.setZeroes(matrix);
    cout << endl;
    cout << "new matrix :" << endl;
    cout << "----------------" << endl;
    print(matrix);
    cout << "----------------" << endl;
    return 0;
}
