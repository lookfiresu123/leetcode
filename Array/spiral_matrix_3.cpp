#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int m, int n) {
        if (m == 0 || n == 0) {
            vector<vector<int>> ret;
            return ret;
        }
        vector<vector<int>> ret(m, vector<int>(n, 0));

        // 假设先从vec[0][-1]的地方跳跃，起初横向跳跃col_step = n次，
        // 纵向跳跃row_step = m-1次。每次跳跃后都要递减col_step或row_step，且
        // 每次跳跃前都要检查col_step和row_step是否大于0，若大于0，则继续执行，
        // 否则退出循环并返回。
        int row_step = m-1, col_step = n;
        int i = 0, j = -1, k = 0;
        while (true) {

            if (col_step <= 0)  break;
            for (int z = 0 ; z < col_step ; ++z)
                ret[i][++j] = ++k;
            --col_step;

            if (row_step <= 0)  break;
            for (int z = 0 ; z < row_step ; ++z)
                ret[++i][j] = ++k;
            --row_step;

            if (col_step <= 0)  break;
            for (int z = 0 ; z < col_step ; ++z)
                ret[i][--j] = ++k;
            --col_step;

            if (row_step <= 0)  break;
            for (int z = 0 ; z < row_step ; ++z)
                ret[--i][j] = ++k;
            --row_step;

        }
        return ret;
    }
};

void print(vector<vector<int>> &ret) {
    for (int i = 0 ; i < ret.size() ; ++i) {
        for (int j = 0 ; j < ret[i].size() ; ++j)
            cout << ret[i][j] << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<int>> ret = sol.generateMatrix(3, 6);
    print(ret);
    return 0;
}
