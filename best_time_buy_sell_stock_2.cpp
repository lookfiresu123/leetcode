#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        vector<int>::size_type length = prices.size();
        if (length > 1) {
            int buy, sell;
            bool buy_lock = false;      // if true can not buy, else do it
            for (vector<int>::size_type i = 0 ; i < length-1 ; ++i) {
                if (prices[i] <= prices[i+1]) {
                    // 买入第i天的股票
                    if (! buy_lock) {
                        // 可以买入
                        buy = prices[i];
                        buy_lock = true;    // 加锁买
                    }
                    sell = prices[i+1];
                    // 最后一天若有利润则卖出
                    if (i == length-2)
                        profit += (sell - buy);
                } else {
                    // 卖出第i天的股票
                    if (buy_lock) {
                        profit += (sell - buy);
                        buy_lock = false;   // 解锁买
                    }
                }
            }
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {0,1,2,1,2,3};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
