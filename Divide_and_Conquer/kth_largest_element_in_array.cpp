#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int>::size_type partition(vector<int> &nums, vector<int>::size_type lo, vector<int>::size_type hi) {
        int temp = nums[lo];
        auto left = lo+1, right = hi;
        while (left <= right) {
            if (nums[left] < temp && nums[right] > temp)
                swap(nums[left], nums[right]);
            if (nums[left] >= temp)     ++left;
            if (nums[right] <= temp)    --right;
        }
        swap(nums[lo], nums[right]);
        return right;
    }

    int findKthLargest(vector<int>& nums, int k) {
        auto pos = nums.size();
        vector<int>::size_type lo = 0;
        auto hi = nums.size()-1;
        while (true) {
            pos = partition(nums, lo, hi);
            if (pos == static_cast<vector<int>::size_type>(k-1))
                return nums[pos];
            else if (pos < static_cast<vector<int>::size_type>(k-1))
                lo = pos + 1;
            else
                hi = pos-1;
        }
    }
};
