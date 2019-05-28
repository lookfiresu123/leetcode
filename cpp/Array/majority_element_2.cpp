#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int base = n / 3;
        vector<int> ret;
        unordered_map<int, int> mymap;  // {value, count}
        for (int i = 0 ; i < n ; ++i)
            if (++mymap[nums[i]] == base+1)
                ret.push_back(nums[i]);
        return ret;
    }
};
