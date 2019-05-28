#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(lower_bound(nums, target));
        ret.push_back(upper_bound(nums, target));
        return ret;
    }
private:
    int lower_bound(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (nums[lo] == target)
            return lo;
        return -1;
    }
    int upper_bound(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if (nums[hi] == target)
            return hi;
        return -1;
    }
};
