#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> vec = {0,1,2};
        for (vector<int>::size_type i = 3 ; i <= static_cast<vector<int>::size_type>(n) ; ++i) {
            if (sqrt(i) == floor(sqrt(i)))
                vec.push_back(1);
            else {
                int min = INT_MAX;
                vector<int>::size_type left = 1, right = i-1;
                while (left <= right) {
                    min = min < vec[left] + vec[right] ? min : vec[left] + vec[right];
                    ++left;
                    --right;
                }
                vec.push_back(min);
            }
        }
        return vec[static_cast<vector<int>::size_type>(n)];
    }
};

int main() {
    Solution sol;
    cout << sol.numSquares(7691) << endl;
    return 0;
}
