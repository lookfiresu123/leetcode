#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        vector<int>::size_type lo = 0, hi = temp.size()-1;
        while (lo < hi) {
            if (temp[lo] + temp[hi] == target)      break;
            else if (temp[lo] + temp[hi] < target)  ++lo;
            else                                    --hi;
        }
        auto i = find(nums.begin(), nums.end(), temp[lo]);
        auto j = find(nums.rbegin(), nums.rend(), temp[hi]);
        ret.push_back(i - nums.begin());
        ret.push_back(nums.size() -1 - (j - nums.rbegin()));
        return ret;
    }
};
