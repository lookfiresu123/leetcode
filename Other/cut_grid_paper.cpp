// 度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，
// 若把网格看成一个坐标轴平行于网格线的坐标系的话，每个点可以用一
// 对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在
// 正方形的内部或者边界。然后把这个正方形剪下来。问剪掉正方形的最
// 小面积是多少。

#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    int getValue(vector<pair<int, int>> &vec) {
        int lx = INT_MAX, rx = INT_MIN;	// most left x, most right x
        int ty = INT_MIN, by = INT_MAX;	// most top y, most bottom y
        for (auto p : vec) {
            lx = min(lx, p.first);
            rx = max(rx, p.first);
            ty = max(ty, p.second);
            by = min(by, p.second);
        }
        int distancex = rx - lx, distancey = ty - by;
        int length_edge = max(distancex, distancey);
        int area = length_edge * length_edge;

        return area;
    }
private:
    int max(int x, int y){
        return x > y ? x : y;
    }
    int min(int x, int y){
        return x < y ? x : y;
    }
};

int main() {
    int n, x, y;
    Solution sol;
    while (cin >> n) {
        vector<pair<int, int>> vec;
        for (int i = 0 ; i < n ; ++i) {
            cin >> x >> y;
            vec.push_back(pair<int, int>(x, y));
        }
        cout << sol.getValue(vec) << endl;
    }
    return 0;
}
