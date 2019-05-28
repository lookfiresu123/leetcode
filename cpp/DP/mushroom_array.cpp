#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Solution {
public:
    // 1. 若有蘑菇，则概率为0；否则，执行第2步
    // 2.1 在最后一行，向右走的概率为1；同理在最后一列时候，向下走概率也为1
    // 2.2 其它情况：p[i][j] = 0.5*p[i][j-1] + 0.5*p[i-1][j]
    double getValue(vector<vector<int>> &vec, int n, int m) {
        double res = 0;
        if (vec[0][0] == 0 && vec[n-1][m-1] == 0) {
            vector<vector<double>> p(n+1, vector<double>(m+1, 0));
            double p1, p2;                      // p1表示从左侧进入的概率，p2表示从上方进入的概率
            for (int i = 1 ; i <= n ; ++i) {
                for (int j = 1 ; j <= m ; ++j) {
                    if (i == 1 && j == 1)
                        p[i][j] = 1;
                    else if (vec[i-1][j-1] == 1)
                        p[i][j] = 0;
                    else {
                        p1 = (i == n ? 1 : 0.5) * p[i][j-1];            // 从左侧(i,j-1)进入(i,j)的概率
                        p2 = (j == m ? 1 : 0.5) * p[i-1][j];            // 从上方(i-1,j)进入(i,j)的概率
                        p[i][j] = p1 + p2;
                    }
                }
            }
            res = p[n][m];
        }
        return res;
    }
};

int main() {
    int n, m, k;
    Solution sol;
    while (cin >> n >> m >> k) {
        vector<vector<int>> vec(n, vector<int>(m, 0));
        int x, y;
        for (int i = 0 ; i < k ; ++i) {
            cin >> x >> y;
            vec[x-1][y-1] = 1;
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << sol.getValue(vec, n, m) << endl;
    }
    return 0;
}
