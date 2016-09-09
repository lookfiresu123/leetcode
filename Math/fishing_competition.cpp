#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Solution {
public:
    // @pos: cc's position
    // @vec: m*n grid
    pair<string, double> getValue(vector<vector<double>> &vec, pair<int, int> &pos, int t) {
        double p_cc = vec[pos.first-1][pos.second-1];   // cc一次钓到的概率
        double p_ss = 0;
        int m = vec.size(), n = vec[0].size();
        for (int i = 0 ; i < m ; ++i)
            for (int j = 0 ; j < n ; ++j)
            	p_ss += vec[i][j];
        p_ss /= (m * n);                                // ss一次钓到的概率

        double pt_cc = 1 - p_cc, pt_ss = 1 - p_ss;
        pt_cc = pow(pt_cc, t);
        pt_ss = pow(pt_ss, t);
        pt_cc = 1 - pt_cc;                              // cc在t分钟后至少钓到一条的概率
        pt_ss = 1 - pt_ss;                              // ss在t分钟后至少钓到一条的概率


        if (pt_cc == pt_ss)
            return pair<string, double>("equal", pt_cc);
        else if (pt_cc < pt_ss)
            return pair<string, double>("ss", pt_ss);
        else
            return pair<string, double>("cc", pt_cc);
    }
};

int main() {
    int m, n, x, y, t;
    Solution sol;
    while (cin >> m >> n >> x >> y >> t) {
        vector<vector<double>> vec(m, vector<double>(n, 0));
        for (int i = 0 ; i < m ; ++i)
            for (int j = 0 ; j < n ; ++j)
            	cin >> vec[i][j];
        pair<int, int> pos(x, y);
        pair<string, double> ret = sol.getValue(vec, pos, t);
        printf("%s\n%.2f\n", ret.first.c_str(), ret.second);
    }
    return 0;
}
