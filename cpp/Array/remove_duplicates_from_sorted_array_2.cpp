#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mymap;
        int length = 0;
        for_each(nums.begin(), nums.end(), [&mymap](int x){++mymap[x];});
        for (auto it = mymap.begin() ; it != mymap.end() ; ++it) {
            if (it->second == 1)
                nums[length++] = it->first;
            else if (it->second >= 2) {
                nums[length++] = it->first;
                nums[length++] = it->first;
            }
        }
        return length;
    }
};
