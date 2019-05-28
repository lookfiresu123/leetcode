#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int>::size_type sz = prices.size();
        if (sz <= 1)
            return 0;
        //  maxprofit_buy[i]：当第i天为买入状态下的最大利润值
        //  maxprofit_sell[i]：当第i天为卖出状态下的最大利润值
        vector<int> maxprofit_buy(sz, 0);
        vector<int> maxprofit_sell(sz, 0);
        maxprofit_buy[0] = 0 - prices[0];
        maxprofit_buy[1] = max(maxprofit_buy[0], 0-prices[1]);
        maxprofit_sell[1] = prices[1] - prices[0];
        for (vector<int>::size_type i = 2 ; i < sz ; ++i) {
            maxprofit_buy[i] = max(maxprofit_buy[i-1], maxprofit_sell[i-2]-prices[i]);
            maxprofit_sell[i] = max(maxprofit_buy[i-1]+prices[i], maxprofit_sell[i-1]);
        }
        return maxprofit_sell[sz-1] > 0 ? maxprofit_sell[sz-1] : 0;
    }
};

int main() {
    Solution sol;
    vector<int> prices1 = {1,2};
    vector<int> prices2 = {2,1,4};
    vector<int> prices3 = {1,2,3,0,2};
    vector<int> prices4 = {2,1};
    cout << sol.maxProfit(prices1) << endl;
    cout << sol.maxProfit(prices2) << endl;
    cout << sol.maxProfit(prices3) << endl;
    cout << sol.maxProfit(prices4) << endl;
    return 0;
}
