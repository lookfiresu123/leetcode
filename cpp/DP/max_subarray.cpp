#include <vector>

using namespace std;

class Solution {
public:
    // @sum[i]：包含第i个元素的最大子序列和
    // @max[i]：在0～i范围内的最大子序列和
    int maxSubArray(vector<int> &vec) {
        int n = vec.size();
        int sum = vec[0];
        int max = vec[0];
        for (int i = 1 ; i < n ; ++i) {
            sum = sum < 0 ? vec[i] : sum+vec[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
};
