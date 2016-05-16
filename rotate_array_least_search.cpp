#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int lo = 0, hi = rotateArray.size()-1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (rotateArray[mid] > rotateArray[hi])   // the min element is in the right side
                lo = mid + 1;
            else if (rotateArray[mid] < rotateArray[hi])  // the min element is in the left side (include the mid self)
                hi = mid;
            else
                --hi;   // reduce the range, because we can still find the min although remove the rotateArray[hi]
        }
        return rotateArray[lo];
    }
};

void print(vector<int> &vec) {
    for (vector<int>::iterator it = vec.begin() ; it != vec.end() ; ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    vector<int> vec = {2,2,2,0,1,1,1,2,2};
    print(vec);
    Solution sol;
    cout << "min is : " << sol.minNumberInRotateArray(vec) << endl;
    return 0;
}
