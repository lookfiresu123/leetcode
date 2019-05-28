#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        auto n = nums.size();
        int sum = 0;
        for (vector<int>::size_type i = 0 ; i < n ; ++i)
            sum += nums[i];
        return n*(n+1)/2 - sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,3,2,4,5};
    cout << sol.missingNumber(nums) << endl;
    return 0;
}
