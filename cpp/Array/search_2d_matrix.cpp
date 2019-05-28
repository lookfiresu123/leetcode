#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        vector<int> temp;
        auto last = matrix[0].size()-1;
        for_each(matrix.begin(), matrix.end(), [&temp, last](vector<int> &vec){ temp.push_back(vec[last]); });
        auto iter = lower_bound(temp.begin(), temp.end(), target);
        if (iter == temp.end())
            return false;
        auto corrent_row = static_cast<vector<vector<int>>::size_type>(iter - temp.begin());
        auto corrent_iter = find(matrix[corrent_row].begin(), matrix[corrent_row].end(), target);
        if (corrent_iter == matrix[corrent_row].end())
            return false;
        return true;
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
