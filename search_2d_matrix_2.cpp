#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchHelper(vector<vector<int>> &matrix, int target, int row_limit, int col_limit, int pos_row, int pos_col) {
        if (pos_row <= row_limit && pos_col >= col_limit) {
            vector<vector<int>>::size_type upos_row = static_cast<vector<vector<int>>::size_type>(pos_row);
            vector<int>::size_type upos_col = static_cast<vector<int>::size_type>(pos_col);
            if (target == matrix[upos_row][upos_col])
                return true;
            else if (target > matrix[upos_row][upos_col]) {
                pos_row = static_cast<int>(upos_row) + 1;
                pos_col = static_cast<int>(upos_col);
                return searchHelper(matrix, target, row_limit, col_limit, pos_row, pos_col);
            } else {
                pos_row = static_cast<int>(upos_row);
                pos_col = static_cast<int>(upos_col) - 1;
                return searchHelper(matrix, target, row_limit, col_limit, pos_row, pos_col);
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row_count = static_cast<int>(matrix.size());
        int col_count;
        if (row_count)
            col_count = matrix[0].size();
        if (row_count && col_count)
            return searchHelper(matrix, target, row_count-1, 0, 0, col_count-1);
        return false;
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
    Solution sol;
    int target = rand() % 100;
    cout << "target  = " << target << endl;
    cout << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;
    return 0;
}
