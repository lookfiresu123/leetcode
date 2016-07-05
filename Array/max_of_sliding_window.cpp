#include <vector>
#include <set>
#include <climits>

using namespace std;

// 求滑动窗口最大值（lintcode）
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        int sz = nums.size(), max = INT_MIN;
        vector<int> ret;
        if (sz > 0 && sz <= k) {
            for (int i = 0 ; i < sz ; ++i)
                max = max < nums[i] ? nums[i] : max;
            ret.push_back(max);
        } else if (sz > k){
            multiset<int> myset;   // { value }
            for (int i = 0 ; i < k ; ++i)
                myset.insert(nums[i]);
            ret.push_back(*myset.rbegin());
            // sliding the window
            for (int i = k ; i < sz ;++i) {
                auto it = myset.find(nums[i-k]);
                myset.erase(it);
                myset.insert(nums[i]);
                ret.push_back(*myset.rbegin());
            }
        }
        return ret;
    }
};
