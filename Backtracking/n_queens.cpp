#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> getValue(int n) {
        vector<vector<int>> vec(n, vector<int>(n, 0));
        vector<vector<vector<int>>> ret;
        solveNQueens(ret, vec, 0, n);   // 在vec[0:n-1][:]范围中找皇后
        return ret;
    }
private:
    // 在vec[row:n-1][:]范围中找皇后
    void solveNQueens(vector<vector<vector<int>>> &ret, vector<vector<int>> &vec, int row, int &n) {
        // 若row == n，则已有一种结果
        if (row == n) {
            ret.push_back(vec);
            return ;
        }
        // 在vec[row:n-1][:]中找皇后
        for (int col = 0 ; col < n ; ++col) {
            if (isValid(vec, row, col, n)) {
                vec[row][col] = 1;
                // 在vec[row+1:n-1][:]中找皇后
                solveNQueens(ret, vec, row+1, n);
                vec[row][col] = 0;
            }
        }
    }

    // 判断vec[row][col]是否能被置为1
    bool isValid(vector<vector<int>> &vec, int row, int col, int n) {
        // 检查同列中是否有其它皇后
        for (int i = 0 ; i < row ; ++i)
            if (vec[i][col] == 1)
                return false;
        // 检查45%斜线上是否有其它皇后
        for (int i = row-1, j = col-1 ; i >= 0 && j >= 0; --i, --j)
            if (vec[i][j] == 1)
                return false;
        // 检查135%斜线上是否有其它皇后
        for (int i = row-1, j = col+1 ; i >= 0 && j < n ; --i, ++j)
            if (vec[i][j] == 1)
                return false;

        return true;
    }
};

void print(vector<vector<vector<int>>> &vecss) {
    for (auto vecs : vecss) {
        for (auto vec : vecs) {
            for (auto i : vec)
                cout << i << " ";
            cout << endl;
        }
        cout << "----------------------" << endl;
    }
}

int main() {
    int n;
    Solution sol;
    while (cin >> n) {
        vector<vector<vector<int>>> ret = sol.getValue(n);
        print(ret);
    }
    return 0;
}
