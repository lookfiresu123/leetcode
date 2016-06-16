#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        map<int, int> mymap;
        for (auto i : nums1)
            mymap[i]++;
        for (auto i : nums2) {
            if (mymap.find(i) != mymap.end() && mymap[i] > 0) {
                mymap[i]--;
                ret.push_back(i);
            }
        }
        return ret;
    }
};

void print(vector<int> &ret) {
    for (auto i : ret)
        cout << i << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {3,5};
    vector<int> ret = sol.intersect(nums1, nums2);
    print(ret);
    return 0;
}
