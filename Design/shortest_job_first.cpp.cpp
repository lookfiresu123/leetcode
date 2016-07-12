#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <cstdio>

using namespace std;

// 短作业优先
class Solution {
public:
    double getValue(deque<pair<int, int>> &dq) {
        int sumtime = 0;
        int n = dq.size();
        sort(dq, 0, n-1);
        if (dq.empty())
            return 0;
        int start = dq.front().first;
        int clock = start;
        auto cmp = [](pair<int, int> x, pair<int, int> y)->bool{ if (x.second == y.second) return x.first > y.first; return x.second > y.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        while (true) {
            // push valid processes to pq
            while (!dq.empty() && clock >= dq.front().first) {
                pq.push(dq.front());
                dq.pop_front();
            }
            // process pq
            if (pq.empty())	++clock;
            else {
                auto p = pq.top();
                pq.pop();
                sumtime += (clock - p.first);
                clock += p.second;
            }
            if (dq.empty() && pq.empty())	break;
        }
        return static_cast<double>(sumtime) / n;
    }
private:
    void sort(deque<pair<int, int>> &dq, int lo, int hi) {
        if (lo < hi) {
            int l = lo, r = hi+1, base = dq[lo].first;
            while (true) {
            	while (l < hi && dq[++l].first < base);
            	while (r > lo && dq[--r].first >= base);
            	if (r <= l)	break;
                swap(dq, l, r);
            }
            swap(dq, lo, r);
        	sort(dq, lo, r-1);
        	sort(dq, r+1, hi);
        }
    }
    void swap(deque<pair<int, int>> &dq, int i, int j) {
        auto tmp = dq[i];
        dq[i] = dq[j];
        dq[j] = tmp;
    }
};

int main() {
    int n;
    Solution sol;
    vector<double> ret;
    while (scanf("%d", &n) != EOF) {
        deque<pair<int, int>> dq(n, pair<int, int>(0, 0));
        for (int i = 0 ; i < n ; ++i)
            scanf("%d %d",&dq[i].first ,&dq[i].second);
        ret.push_back(sol.getValue(dq));
    }
    for (int i = 0 ; i < ret.size() ; ++i)
        printf("%.4f\n", ret[i]);
    return 0;
}
