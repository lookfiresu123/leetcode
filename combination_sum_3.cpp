#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    // @n : 还有多少步
    void combinationSum3_helper(vector<vector<int>> &ret, vector<int> temp, int n, int k) {
        if (temp.size() == static_cast<vector<int>::size_type>(k) && n == 0) {
            ret.push_back(temp);
            return ;
        } else if (temp.size() < static_cast<vector<int>::size_type>(k) && n > 0) {
            for (int i = (temp.empty() ? 1 : temp.back()+1) ; i <= 9 ; ++i) {     // 按升序循环
                if (n - i < 0) break;
                temp.push_back(i);
                combinationSum3_helper(ret, temp, n-i, k);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> temp;
        deque<int> vals = {1,2,3,4,5,6,7,8,9};
        combinationSum3_helper(ret, temp, n, k);
        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ret = sol.combinationSum3(3, 7);
    return 0;
}
