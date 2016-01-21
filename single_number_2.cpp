#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        const int base = 3;
        int mask, res = 0;
        int int_size = static_cast<int>(sizeof(int) * 8);
        for (int i = 0 ; i < int_size ; ++i) {
            mask = 1 << i;     // x充当掩码的作用
            int sum = 0;
            for (vector<int>::size_type j = 0 ; j < nums.size() ; ++j) {
                if (mask & nums[j])
                    ++sum;
            }
            if (sum % base)
                res = res | mask;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,2,3,4,5,4,3,2,1,0,2,1,0,4,3};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}
