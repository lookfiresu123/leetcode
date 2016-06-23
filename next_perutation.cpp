#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return ;
        for (int i = len-1, j = i-1 ; j >= 0 ; --i, --j) {
            if (nums[i] > nums[j]) {
                int z = nums[j];
                for (int k = len-1 ; k >= i ; --k) {
                    if (z < nums[k]) {
                        swap(nums, j, k);
                        break;
                    }
                }
                sort(nums.begin()+j+1, nums.end());
                return ;
            }
        }
        for (int i = 0, j = len-1 ; i < j ; ++i, --j)
            swap(nums, i, j);
    }
private:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

void print(vector<int> &nums) {
    for_each(nums.begin(), nums.end(), [](int x){ cout << x << " "; });
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {3,1,2};
    sol.nextPermutation(nums);
    return 0;
}
