#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    // range_sum[i:j] = sum[:j] - sum[:i-1] = nums[0..j] - nums[0..i-1]
    // sum[:-1] = 0, sum[:0] = nums[0], ..., sum[:j] = nums[0..j]
    // lower <= range_sum[i:j] <= upper  ->  lower <= sum[:j] - sum[:i-1] <= upper
    // -> sum[:j] - upper <= sum[:i-1] <= sum[:j] - lower

    // 因为i <= j -> i-1 < j, 所以我们将sum[:i-1]插入一个multiset中,
    // 然后lower_bound(sum[:j] - upper)和upper_bound(sum[:j] - lower)
    // 之间的距离即是当cnt[:j] = cnt(range_sum[:j])的总计数。最后计数
    // cnt[:] = cnt(range_sum[:])即可。

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long int> myset;          // 防止越界, 且myset中存入的是sum[:i-1]，即在计数过程中的元素范围为sum[:-1] ~ sum[:j-1]
        int sz = nums.size();
        int cnt = 0;

        vector<long long int> sums(sz, 0);      // sum[0:sz-1]
        long long int tmp = 0;
        for (int i = 0 ; i < sz ; ++i) {
            tmp += nums[i];
            sums[i] = tmp;
        }

        long long int sum = 0;       // sum[:-1]
        myset.insert(sum);

        for (int j = 0 ; j < sz ; ++j) {
            sum = sums[j];
            // 计数multiset中满足条件sum[:j] - upper <= sum[:i-1] <= sum[:j] - lower的元素（sum[:i-1]）数量
            cnt += distance(myset.lower_bound(sum - upper), myset.upper_bound(sum - lower));
            myset.insert(sum);
        }
        return cnt;
    }
};
