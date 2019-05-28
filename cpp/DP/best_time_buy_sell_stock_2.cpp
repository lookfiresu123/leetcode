#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size() + 1;
        vector<int> maxprofit_buy(sz, INT_MIN);
        vector<int> maxprofit_sell(sz, 0);
        for (int i = 1 ; i < sz ; ++i) {
            maxprofit_buy[i] = max(maxprofit_buy[i-1], maxprofit_sell[i-1] - prices[i-1]);      // 当第i-1天为买入状态时，股民手上现金的最大值
            maxprofit_sell[i] = max(maxprofit_sell[i-1], maxprofit_buy[i-1] + prices[i-1]);     // 当第i-1天为卖出状态时，股民手上现金的最大值
        }
        return maxprofit_sell[sz-1];
    }
};

// 若允许买卖在同一天进行，则还有如下方法
class Solution_Advance {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        int sz = prices.size();
        for (int i = 1 ; i < sz ; ++i)
            ret += max(prices[i] - prices[i-1], 0);     // 若明天股价上涨则持续买入，利润增加为prices[i]-prices[i-1]；若明天股价下跌则赶紧卖出，利润增加0
        return ret;
    }
};

int main() {
    vector<int> prices = {0,1,2,1,2,3};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
