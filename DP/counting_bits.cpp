#include <vector>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    int count_1(bitset<32> &set) {
        int count = 0;
        for (size_t i = 0 ; i < 32 ; ++i)
            if (set[i])
                ++count;
        return count;
    }

    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i = 0 ; i <= num ; ++i) {
            bitset<32> set(i);
            ret.push_back(count_1(set));
        }
        return ret;
    }
};

int main() {
    Solution sol;
    int num = 5;
    vector<int> ret = sol.countBits(num);
    for_each(ret.cbegin(), ret.cend(), [](int i)->void{ cout << i << endl; });
    return 0;
}
