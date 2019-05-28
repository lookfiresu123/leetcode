#include <vector>
#include <iostream>

using namespace std;

class Exception {};

// 获得极大值点的索引
class Solution {
public:
    int findPeakElement_helper(vector<int> &nums, vector<int>::size_type lo, vector<int>::size_type hi) {
        auto mid = lo + (hi - lo) / 2;
        if ((mid == lo && mid == hi) || (mid == lo && nums[mid] > nums[mid+1]) || (mid == hi && nums[mid] > nums[mid-1]))
            return mid;
        else if (mid < hi && nums[mid] < nums[mid+1])   // 极大值点出现在mid的右边
            findPeakElement_helper(nums, mid+1, hi);
        else if (mid > lo && nums[mid] < nums[mid-1])   // 极大值点出现在mid的左边
            findPeakElement_helper(nums, lo, mid-1);
        else
            return mid;
        return 0;
    }

    int findPeakElement(vector<int>& nums) {
        try {
            if (nums.empty())
                throw Exception();
        } catch (Exception) {
            cout << "nums should not be empty!" << endl;
            exit(0);
        }
        vector<int>::size_type lo = 0, hi = nums.size()-1;
        return findPeakElement_helper(nums, lo, hi);
    }
};
