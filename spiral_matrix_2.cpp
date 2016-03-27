#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        if (n == 0)
            return ret;
        if (n == 1) {
            ret = {{1}};
            return ret;
        }
        for (int i = 0 ; i < n ; ++i) {     // 初始化ret
            vector<int> temp(n, 0);
            ret.push_back(temp);
        }
        int times = 0;
        vector<int>::size_type right_first = 0, right_last = n-1;
        vector<int>::size_type left_first = n-2, left_last = 0;
        vector<vector<int>>::size_type down_first = 1, down_last = n-1;
        vector<vector<int>>::size_type up_first = n-2, up_last = 1;
        int sum = n * n;
        vector<vector<int>>::size_type i = 0;
        vector<int>::size_type j = 0;
        for (int k = 1 ; k <= sum ; ++k) {
            if (times % 4 == 0 && j <= right_last) {
                ret[i][j] = k;
                if (j < right_last)
                    ++j;
                else {
                    ++times;
                    if (right_last) --right_last;
                    ++right_first;
                    ++i;
                }
            } else if (times % 4 == 1 && i <= down_last) {
                ret[i][j] = k;
                if (i < down_last)
                    ++i;
                else {
                    ++times;
                    if (down_last) --down_last;
                    ++down_first;
                    if (j) --j;
                }
            } else if (times % 4 == 2 && i >= left_last) {
                ret[i][j] = k;
                if (j > left_last)
                    --j;
                else {
                    ++times;
                    if (left_first) --left_first;
                    ++left_last;
                    if (i) --i;
                }
            } else if (times % 4 == 3 && i >= up_last) {
                ret[i][j] = k;
                if (i > up_last)
                    --i;
                else {
                    ++times;
                    if (up_first) --up_first;
                    ++up_last;
                    ++j;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    int n = 0;
    vector<vector<int>> ret = sol.generateMatrix(n);
    for (vector<vector<int>>::size_type i = 0 ; i < ret.size() ; ++i) {
        for (vector<int>::size_type j = 0 ; j < ret.size() ; ++j)
            cout << ret[i][j] << " ";
        cout << endl;
    }
    return 0;
}
