#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int ret = nums[0];
        for (int i = 0 ; i < len-1 ; ++i) {
            if (nums[i] <= nums[i+1])   // 略过前半段正序的部分（有可能最小值也处于正序之中，此时有两种可能，一种是完全正序，另一种是所有元素值都相同）
                continue;
            else {                      // 当第一次遇到逆序时跳出循环，并返回引发该逆序的元素
                ret = nums[i+1];
                break;
            }
        }
        return ret;
    }
};
