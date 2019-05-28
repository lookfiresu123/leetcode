#include <vector>
#include <algorithm>

using namespace std;

// Given an array S of n integers, are there elements a, b, c in S such that a
// + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        int sz = nums.size(), target = 0;
        int max = nums[sz-1];
        for (int i = 0 ; i < sz-2 ; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] * 3 > target)
                break;
            if (nums[i] + 2 * max < target)
                continue;
            int lo = i+1, hi = sz-1;
            twoSumForThree(ret, nums, lo, hi, nums[i], target-nums[i]);
        }
        return ret;
    }
private:
    void twoSumForThree(vector<vector<int>> &ret, vector<int>& nums, int lo, int hi, int z, int target) {
        int max = nums[hi];
        for (int i = lo ; i < hi ; ++i) {
            if (i > lo && nums[i] == nums[i-1])
                continue;
            if (nums[i] * 2 > target)
                break;
            if (nums[i] + max < target)
                continue;
            for (int j = i+1 ; j <= hi ; ++j) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                if (nums[i] + nums[j] > target)
                    break;
                else if (nums[i] + nums[j] == target) {
                    vector<int> tmp;
                    tmp.push_back(z);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    ret.push_back(tmp);
                }
            }
        }
    }
};
