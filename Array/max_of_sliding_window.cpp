#include <vector>
#include <set>
#include <climits>

using namespace std;

// 求滑动窗口最大值（lintcode）
// O(N log k)，利用最大堆。
class Solution1 {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     * time cost: O(n*log(k))
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        int sz = nums.size(), max = INT_MIN;
        vector<int> ret;
        if (sz > 0 && sz <= k) {
            // 若数组中元素个数不大于k，则找到数组中的最大值即可
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

// 我们用双向队列可以在O(N)时间内解决这题。当我们遇到新的数时，将新的数和双向队列的末尾比较，如果末尾比新数小，则把末尾扔掉，直到该队列的末尾比新数大或者队列为空的时候才住手。这样，我们可以保证队列里的元素是从头到尾降序的。因此队列头结点便对应最大值。
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty())
            return res;
        int n = nums.size();
        deque<int> dq;
        for (int i = 0 ; i < n ; ++i) {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k-1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
