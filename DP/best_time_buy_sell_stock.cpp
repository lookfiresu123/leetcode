#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size() + 1;
        vector<int> max_profit(sz, 0);
        vector<int> min_price(sz, INT_MAX);
        for (int i = 1 ; i < sz ; ++i) {
            max_profit[i] = max(max_profit[i-1], prices[i-1] - min_price[i-1]);     // 计算第0～i天的最高利润
            min_price[i] = min(min_price[i-1], prices[i-1]);                        // 计算第0～i天的最低股价
        }
        return max_profit[sz-1];
    }
};
