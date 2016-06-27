#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int start = 0, end = start;
        int sum = 0;
        int min_len = INT_MAX;
        int n = nums.size();
        while (end < n) {
            while (end < n && (sum += nums[end]) < s)
                ++end;
            if (end == n && start == 0)
                return 0;
            else if (end == n)
                return min_len;
            min_len = (end-start+1) < min_len ? (end-start+1) : min_len;
            while (start < end && (sum -= nums[start]) >= s)
                ++start;
            if (start == end)
                return 1;

            min_len = (end-start+1) < min_len ? (end-start+1) : min_len;
            ++start;
            ++end;
        }
        return min_len;
    }
};

int main() {
    Solution sol;
    return 0;
}
