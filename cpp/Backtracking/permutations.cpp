#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> &swap(vector<int>& nums, vector<int>::size_type i, vector<int>::size_type j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return nums;
    }

    void permute_helper(vector<vector<int>> &ret, vector<int> nums, vector<int>::size_type lo, vector<int>::size_type hi) {
        if (lo == hi)
            ret.push_back(nums);
        else {
            for (vector<int>::size_type i = lo ; i <= hi ; ++i) {
                swap(nums, lo, i);
                permute_helper(ret, nums, lo+1, hi);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int>::size_type sz = nums.size();
        if (sz == 0)
            return ret;
        permute_helper(ret, nums, 0 , nums.size()-1);
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,2,3,4};
    vector<vector<int>> ret = sol.permute(vec);
    auto sz1 = ret.size();
    for (vector<vector<int>>::size_type i = 0 ; i < sz1 ; ++i) {
        auto temp = ret[i];
        auto sz2 = ret[i].size();
        for (vector<int>::size_type j = 0 ; j < sz2 ; ++j)
            cout << temp[j] << " ";
        cout << endl;
    }
    return 0;
}
