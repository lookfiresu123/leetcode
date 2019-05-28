#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 计算你能获得的最大收益
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax_Per(vector<int> &prices, int lo, int hi, vector<int> &b, vector<int> &s) {
        if (lo >= hi)
            return 0;
		b[lo] = 0 - prices[lo], s[lo] = 0;	// b[i]表示当第i天状态为买入时，当天的最大利润值；s[i]表示当第i天状态为卖出时，当天的最大利润值
        for (int i = lo+1 ; i <= hi ; ++i) {
            s[i] = max(b[i-1] + prices[i], s[i-1]);
            b[i] = max(b[i-1], 0 - prices[i]);
        }
        return s[hi];		// 一定要保证第hi天的状态是卖出的
    }

    int calculateMax(vector<int> prices) {
        int max = 0, sz = prices.size();
        vector<int> b(sz, 0), s(sz, 0);
		for (int i = 0 ; i < sz ; ++i) {
            int temp1 = calculateMax_Per(prices, 0, i, b, s);
            int temp2 = calculateMax_Per(prices, i+1, sz-1, b, s);
            int temp = temp1 + temp2;
            cout << i << ": " << "temp1 = " << temp1 << ", temp2 = "<< temp2 << ", temp = " << temp << endl;
			max = max > temp ? max : temp;
        }
        return max;
    }
};

int main() {
    // vector<int> prices1 = {61,8,81,67,80,47};
    vector<int> prices2 = {3,8,5,1,7,8};
    Solution sol;
    sol.calculateMax(prices2);
    return 0;
}
