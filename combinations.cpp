#include <vector>
#include <iterator>
#include <iostream>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void combine_helper(vector<vector<int>> &ret, vector<int> temp, int n, vector<int>::size_type k) {
        if (temp.size() == k) {
            ret.push_back(temp);
            return ;
        }
        for (int j = (temp.empty() ? 1 : temp.back()+1) ; j <= n ; ++j) {
            temp.push_back(j);
            combine_helper(ret, temp, n, k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (n < k || k == 0)
            return ret;
        vector<int> temp;
        combine_helper(ret, temp, n, static_cast<vector<int>::size_type>(k));
        return ret;
    }
};

void print(vector<vector<int>> &matrix) {
    for (auto iter = matrix.begin() ; iter != matrix.end() ; ++iter) {
        for_each(iter->begin(), iter->end(), [](int x){ cout << x << " "; });
        cout << endl;
    }
}


int main() {
    vector<vector<int>> matrix;
    Solution sol;
    int k = 2, n = 4;
    matrix = sol.combine(n, k);
    cout << "matrix :" << endl;
    cout << "----------------" << endl;
    print(matrix);
    cout << "----------------" << endl;
    return 0;
}
