#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        // 假设数组中至少有一个元素
        int min = INT_MAX;
        vector<int>::size_type sz = nums.size();
        for (vector<int>::size_type i = 0 ; i < sz ; ++i)
            min = (min > nums[i] ? nums[i] : min);
        return min;
    }
};
