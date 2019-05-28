# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;  // { value, index }
        unordered_map<int, int>::iterator it;
        for (int i = 0 ; i < nums.size() ; ++i) {
            if ((it = mymap.find(nums[i])) != mymap.end() && i - it->second <= k)
                return true;
            mymap[nums[i]] = i;
        }
        return false;
    }
};
