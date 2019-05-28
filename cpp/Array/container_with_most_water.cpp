#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2)
            return 0;
        // 先计算最两端的line组成的容器
        vector<int>::size_type hi = height.size()-1;
        vector<int>::size_type lo = 0;
        int h = height[lo] < height[hi] ? height[lo] : height[hi];
        int area = h * (hi - lo);
        int max = area;
        // 若之间的line要组成更大的容器，则必须要有更大的h才行，而该line的长度也必须大于h
        while (lo < hi) {
            while (height[lo] <= h && lo < hi)      ++lo;
            while (height[hi] <= h && lo < hi)      --hi;
            h = height[lo] < height[hi] ? height[lo] : height[hi];
            area = h * (hi - lo);
            max = max < area ? area : max;
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,7,4,3,9,6,7,7,4};
    cout << sol.maxArea(vec) << endl;
    return 0;
}
