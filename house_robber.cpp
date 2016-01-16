#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        } else {
            if (nums.size() == 1)
                return nums[0];
            else {
                vector<int> max_money(nums.size());
                max_money[0] = nums[0];
                max_money[1] = std::max(max_money[0], nums[1]);
                for (vector<int>::size_type i = 2 ; i < nums.size() ; ++i)
                    max_money[i] = std::max(max_money[i-1], max_money[i-2]+nums[i]);
                return max_money[nums.size() - 1];
            }
        }
    }
};

int main () {
    vector<int> v = {2,1,1,2};
    Solution sol;
    std::cout << sol.rob(v) << std::endl;
    return 0;
}
