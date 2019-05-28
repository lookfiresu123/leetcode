#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // using dynamic programming
    int rob(vector<int> &nums) {
        int n = nums.size() + 2;
        vector<int> max_pos(n, 0);
        int tmp1, tmp2;
        for (int i = 2 ; i < n ; ++i) {
            tmp1 = max_pos[i-2] + nums[i-2];
            tmp2 = max_pos[i-1];
            max_pos[i] = tmp1 > tmp2 ? tmp1 : tmp2;
        }
        return max_pos[n-1];
    }
};

int main() {
    vector<int> nums = {4,2,3,6,7,1};
    Solution sol;
    cout << sol.rob(nums) << endl;
    return 0;
}
