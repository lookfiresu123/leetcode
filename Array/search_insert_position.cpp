#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int>::size_type searchInsert_helper(vector<int> &nums, int target, vector<int>::size_type low_index, vector<int>::size_type high_index) {
        if (low_index <= high_index) {
            vector<int>::size_type mid_index = low_index + (high_index - low_index) / 2;
            if (nums[mid_index] == target)
                return mid_index;
            else if (nums[mid_index] < target)
                return searchInsert_helper(nums, target, mid_index+1, high_index);
            else if (nums[mid_index] > target && mid_index > 0)     // 防止溢出
                return searchInsert_helper(nums, target, low_index, mid_index-1);
            else
                return 0;
        } else
            return low_index;
    }

    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty())
            return 0;
        return static_cast<int>(searchInsert_helper(nums, target, 0, nums.size()-1));
    }
};

int main() {
    Solution sol;
    vector<int> v2 = {1,3,5,6};
    // vector<int> v2;
    cout << "target = 5, index = " << sol.searchInsert(v2, 5) << endl;
    cout << "target = 2, index = " << sol.searchInsert(v2, 2) << endl;
    cout << "target = 7, index = " << sol.searchInsert(v2, 7) << endl;
    cout << "target = 1, index = " << sol.searchInsert(v2, 1) << endl;
    cout << "target = 0, index = " << sol.searchInsert(v2, 0) << endl;
    return 0;
}
