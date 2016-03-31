#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return ;
        vector<pair<vector<vector<int>>::size_type, vector<int>::size_type>> temp;
        for (vector<vector<int>>::size_type i = 0 ; i < matrix.size() ; ++i) {
            vector<int>::size_type j = 0;
            while ((j = find((matrix[i].begin()+j), matrix[i].end(), 0) - matrix[i].begin()) < matrix[i].size()) {
                temp.push_back(make_pair(i,j));
                ++j;
            }
        }
        for (auto it = temp.begin() ; it != temp.end() ; ++it) {
            auto cur_row = it->first;
            auto cur_col = it->second;
            for (vector<int>::size_type i = 0 ; i < matrix[cur_row].size() ; ++i)
                matrix[cur_row][i] = 0;
            for (vector<vector<int>>::size_type i = 0 ; i < matrix.size() ; ++i)
                matrix[i][cur_col] = 0;
        }
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
    matrix[0][0] = 0;
    matrix[2][2] = 0;
    cout << "matrix :" << endl;
    cout << "----------------" << endl;
    print(matrix);
    cout << "----------------" << endl;
    Solution sol;
    sol.setZeroes(matrix);
    cout << endl;
    cout << "new matrix :" << endl;
    cout << "----------------" << endl;
    print(matrix);
    cout << "----------------" << endl;
    return 0;
}
