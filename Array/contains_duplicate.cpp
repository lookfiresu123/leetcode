#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2)
            return false;
        // 排序
        sort(nums.begin(), nums.end());
        for (vector<int>::size_type i = 0 ; i < nums.size()-1 ; ++i) {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
