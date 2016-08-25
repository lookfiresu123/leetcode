#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 0 ; i < n ; ++i) {
            int l = (i-1) % n, r = (i+1) % n;
            if (nums[l] > nums[i] && nums[r] > nums[i])
                return nums[i];
        }
        return nums[0];
    }
};
