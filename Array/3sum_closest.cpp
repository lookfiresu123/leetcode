#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

// Given an array S of n integers, find three integers in S such that the sum
// is closest to a given number, target. Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0]+nums[1]+nums[2];
        int tmp;
        for (int i = 0 ; i < sz-2 ; ++i) {
            if (i > 0 && nums[i-1] == nums[i])
                continue;
            if ((tmp = nums[i] + nums[i+1] + nums[i+2]) >= target) {
                closest_sum = abs(closest_sum-target) > abs(tmp-target) ? tmp : closest_sum;
                break;
            }
            if ((tmp = nums[i] + nums[sz-2] + nums[sz-1]) <= target) {
                closest_sum = abs(closest_sum-target) > abs(tmp-target) ? tmp : closest_sum;
                continue;
            }
            tmp = nums[i] + twoSumClosest(nums, i+1, sz-1, target-nums[i]);
            closest_sum = abs(closest_sum-target) > abs(tmp-target) ? tmp : closest_sum;
        }
        return closest_sum;
    }
private:
    int twoSumClosest(vector<int> &nums, int lo, int hi, int target) {
        int closest_sum = nums[lo]+nums[lo+1];
        int tmp;
        for (int i = lo ; i < hi ; ++i) {
            if (i > lo && nums[i-1] == nums[i])
                continue;
            if ((tmp = nums[i] + nums[i+1]) >= target) {
                closest_sum = abs(closest_sum-target) > abs(tmp-target) ? tmp : closest_sum;
                break;
            }
            if ((tmp = nums[i] + nums[hi]) <= target) {
                closest_sum = abs(closest_sum-target) > abs(tmp-target) ? tmp : closest_sum;
                continue;
            }
            for (int j = i+1 ; j <= hi ; ++j) {
                tmp = nums[i] + nums[j];
                closest_sum = abs(closest_sum-target) > abs(tmp-target) ? tmp : closest_sum;
            }
        }
        return closest_sum;
    }
};
