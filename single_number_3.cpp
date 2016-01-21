#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        for (vector<int>::size_type i = 0 ; i < nums.size() ; ++i)
            r ^= nums[i];
        // 仅保留r中的最后一个1，其余设为0
        int flag = r & (~(r-1));
        int a = 0, b = 0;
        for (vector<int>::size_type i = 0 ; i < nums.size() ; ++i) {
            if ((nums[i] & flag) == 0)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};
