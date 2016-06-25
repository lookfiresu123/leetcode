#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 由于元素类型为int，但只用了一位来保持旧值，因此使用第二位来保存新值，在最后右移一位即可
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty() || board[0].empty())
            return ;
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());

        int cnt_live, cnt_dead;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                cnt_live = 0, cnt_dead = 0;
                for (int k1 = max(i-1, 0) ; k1 < min(i+2, m) ; ++k1) {
                    for (int k2 = max(j-1, 0) ; k2 < min(j+2, n); ++k2) {
                        if ((board[k1][k2] & 1) == 1)
                            ++cnt_live;
                        else
                            ++cnt_dead;
                    }
                }
                if ((board[i][j] & 1) == 1) {
                    if (cnt_live - 1 < 2)
                        board[i][j] |= 1;
                    else if (2 <=  cnt_live && cnt_live - 1 <= 3)
                        board[i][j] |= 2;
                    else if (cnt_live > 3)
                        board[i][j] |= 1;
                } else if (cnt_live == 3)
                    board[i][j] |= 2;
            }
        }

        for (int i = 0 ; i < m ; ++i)
            for (int j = 0 ; j < n ; ++j)
                board[i][j] >>= 1;
    }
};
