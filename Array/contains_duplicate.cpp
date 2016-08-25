#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mymap;
        for (auto i : nums) {
            if (mymap.find(i) != mymap.end())
                return true;
            mymap[i]++;
        }
        return false;
    }
};
