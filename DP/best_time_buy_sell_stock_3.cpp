#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 计算你能获得的最大收益，其中至多买卖两次
     *
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {
        int sz = prices.size();
        if (sz <= 1)	return 0;

		// 从左到右扫描，只买一次
        vector<int> vecl(sz, 0);	// vecl[i]表示第0天到第i天的最大利润
        int min_price = prices[0];
        for (int i = 1 ; i < sz ; ++i) {
            vecl[i] = max(vecl[i-1], prices[i] - min_price);
            min_price = min(prices[i], min_price);
        }

        // 从右到左扫描，只买一次
        vector<int> vecr(sz, 0);	// vecr[i]表示表示第i天到第sz-1天的最大利润
        int max_price = prices[sz-1];
        for (int i = sz-2 ; i >= 0 ; --i) {
            vecr[i] = max(vecr[i+1], max_price - prices[i]);
            max_price = max(prices[i], max_price);
        }

        int max_profit = 0;
        for (int i = 0 ; i < sz ; ++i)
            max_profit = max(max_profit, vecl[i]+vecr[i]);
        return max_profit;
    }
};
