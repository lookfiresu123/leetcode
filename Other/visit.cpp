#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class Visit {
public:
    void initsumPath(vector<vector<int>> &map, vector<vector<int>> &sum_path, pair<int, int> &pos_manager, int n, int m) {
		int i = pos_manager.first, j = pos_manager.second;
        while (i >= 0 && map[i][pos_manager.second] != -1)
            sum_path[i--][pos_manager.second] = 1;
        i = pos_manager.first;
        while (i < n && map[i][pos_manager.second] != -1)
            sum_path[i++][pos_manager.second] = 1;
        while (j >= 0 && map[pos_manager.first][j] != -1)
            sum_path[pos_manager.first][j--] = 1;
        j = pos_manager.second;
        while (j < m && map[pos_manager.first][j] != -1)
            sum_path[pos_manager.first][j++] = 1;
    }

    int countPath(vector<vector<int> > map, int n, int m) {
        // write code here
        // 先找到经理和商家的位置
        vector<int>::iterator it1, it2;
        pair<int, int> pos_manager(0,0), pos_customer(0,0);		// 分别表示经理和商家的地址
        for (int i = 0 ; i < n ; ++i) {
            if ((it1 = find(map[i].begin(), map[i].end(), 1)) != map[i].end()) {
				pos_manager.first = i;
                pos_manager.second = it1 - map[i].begin();
                break;
            }
        }
        for (int i = 0 ; i < n ; ++i) {
			if ((it2 = find(map[i].begin(), map[i].end(), 2)) != map[i].end()) {
                pos_customer.first = i;
                pos_customer.second = it2 - map[i].begin();
                break;
            }
        }
        // 计算路径
        vector<vector<int>> sum_path(n, vector<int>(m, 0));
		initsumPath(map, sum_path, pos_manager, n, m);
        // 若商家和经理在同一直线上
        if (pos_customer.first == pos_manager.first || pos_customer.second == pos_manager.second)
            return sum_path[pos_customer.first][pos_customer.second];
        // 若商家在经理的左上方
        else if (pos_customer.first < pos_manager.first && pos_customer.second < pos_manager.second) {
            for (int i = pos_manager.first - 1 ; i >= pos_customer.first ; --i) {
                for (int j = pos_manager.second - 1 ; j >= pos_customer.second ; --j) {
                    sum_path[i][j] += (map[i+1][j] == -1 ? 0 : sum_path[i-1][j]);
                    sum_path[i][j] += (map[i][j+1] == -1 ? 0 : sum_path[i][j-1]);
                }
            }
            return sum_path[pos_customer.first][pos_customer.second];
        }
        // 若商家在经理的左下方
        else if (pos_customer.first < pos_manager.first && pos_customer.second > pos_manager.second) {
             for (int i = pos_manager.first + 1 ; i <= pos_customer.first ; ++i) {
                for (int j = pos_manager.second - 1 ; j >= pos_customer.second ; --j) {
                    sum_path[i][j] += (map[i-1][j] == -1 ? 0 : sum_path[i-1][j]);
                    sum_path[i][j] += (map[i][j+1] == -1 ? 0 : sum_path[i][j+1]);
                }
            }
            return sum_path[pos_customer.first][pos_customer.second];
        }
        // 若商家在经理的右上方
        else if (pos_customer.first > pos_manager.first && pos_customer.second < pos_manager.second) {
            for (int i = pos_manager.first - 1 ; i >= pos_customer.first ; --i) {
                for (int j = pos_manager.second + 1 ; j <= pos_customer.second ; ++j) {
                    sum_path[i][j] += (map[i+1][j] == -1 ? 0 : sum_path[i+1][j]);
                    sum_path[i][j] += (map[i][j-1] == -1 ? 0 : sum_path[i][j-1]);
                }
            }
            return sum_path[pos_customer.first][pos_customer.second];
        }
        // 若商家在经理的右下方
        else if (pos_customer.first > pos_manager.first && pos_customer.second > pos_manager.second) {
            for (int i = pos_manager.first + 1 ; i <= pos_customer.first ; ++i) {
                for (int j = pos_manager.second + 1 ; j <= pos_customer.second ; ++j) {
                    sum_path[i][j] += (map[i-1][j] == -1 ? 0 : sum_path[i-1][j]);
                    sum_path[i][j] += (map[i][j-1] == -1 ? 0 : sum_path[i][j-1]);
                }
            }
            return sum_path[pos_customer.first][pos_customer.second];
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> map = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,1,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,2}};
    Visit vis;
    cout << vis.countPath(map, 7, 5) << endl;
    return 0;
}
