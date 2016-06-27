#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 递归：超时
    /*
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        else {
            int sum = 0;
            for (int i = 1 ; i <=n ; ++i)
                sum += numTrees(i-1) * numTrees(n-i);
            return sum;
        }
    }
    */

    // 迭代
    int numTrees(int n) {
        vector<int> sum(n+1, 0);
        // 初始化
        sum[0] = 1;
        sum[1] = 1;
        for (int i = 2 ; i <= n ; ++i) {    // 计算sum[i]
            for (int j = 0 ; j <= i-1 ; ++j)
                sum[i] += sum[j] * sum[i-j-1];
        }
        return sum[n];
    }
};

int main() {
    Solution sol;
    cout << sol.numTrees(19) << endl;
    return 0;
}
