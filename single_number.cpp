#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int base = 0;
        for (auto iter = nums.begin() ; iter != nums.end() ; ++iter)
            base ^= *iter;
        return base;
    }
};
