#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 首先我们选择从左下角开始搜寻，(为什么不从左上角开始搜寻，左上角向右和向下都是递增，那么对于一个点，对于向右和向下会产生一个岔路；如果我们选择从左下脚开始搜寻的话，如果大于就向右，如果小于就向上)。
    bool Find(vector<vector<int> > array, int target) {
        if (array.empty() || array[0].empty())
            return false;
        int sz_row = array.size(), sz_col = array[0].size();
        for (int row = sz_row-1, col = 0 ; row >= 0 && col < sz_col ; ) {
            if (target == array[row][col])
                return true;
            else if (target < array[row][col])
                --row;
            else
                ++col;
        }
        return false;
   }
};

int main() {
    vector<vector<int> > array = {{1,4,7},{2,5,8},{3,6,9}};
    int target = 2;
    Solution sol;
    cout << (sol.Find(array, target) ? "true" : "false") << endl;
    return 0;
}
