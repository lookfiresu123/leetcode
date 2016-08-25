#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;  // { value, count }
        for_each(nums.begin(), nums.end(), [&mymap](int x){ mymap[x]++; });
        auto cmp = [](pair<int, int> x, pair<int, int> y)->bool{ return x.second > y.second; };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        int i = 0;
        for (auto it = mymap.begin() ; it != mymap.end() ; ++it, ++i) {
            pq.push(*it);
            if (i >= k)     pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        for (int i = 0, j = res.size()-1 ; i < j ; ++i, --j)
            swap(res, i, j);
        return res;
    }
private:
    void swap(vector<int> &vec, int i, int j) {
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }
};
