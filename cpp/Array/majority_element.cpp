#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0], sz = nums.size();
        int cnt = 1;
        for (int i = 1 ; i < sz ; ++i) {
            if (cnt == 0) {
                ret = nums[i];
                ++cnt;
            } else if (ret == nums[i])
                ++cnt;
            else
                --cnt;
        }
        return ret;
    }
};
