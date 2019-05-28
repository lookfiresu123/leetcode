#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // divide into two problem :
        // if we do not rob house n-1, then we rob nums[0 ... n-2]
        // else if we rob house n-1, then we rob nums[1 ... n-1]
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        vector<int> max_pos1(n+1, 0), max_pos2(n+1, 0);
        int tmp1, tmp2;
        for (int i = 2 ; i < n+1 ; ++i) {
            tmp1 = max_pos1[i-2] + nums[i-2];
            tmp2 = max_pos1[i-1];
            max_pos1[i] = tmp1 > tmp2 ? tmp1 : tmp2;
        }
        for (int i = 2 ; i < n+1 ; ++i) {
            tmp1 = max_pos2[i-2] + nums[i-1];
            tmp2 = max_pos2[i-1];
            max_pos2[i] = tmp1 > tmp2 ? tmp1 : tmp2;
        }
        return max_pos1[n] > max_pos2[n] ? max_pos1[n] : max_pos2[n];
    }
};

int main() {
    vector<int> nums = {3,4,5,6,7};
    Solution sol;
    cout << sol.rob(nums) << endl;
    return 0;
}
