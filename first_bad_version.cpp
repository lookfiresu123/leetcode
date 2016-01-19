// Forward declaration of isBadVersion API.
#include <iostream>

using namespace std;

const size_t size = 2;

static bool versions[size] = {false, false};

bool isBadVersion(int version) {
    return versions[version-1];
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        while (left < right) {
            // mid = (left + right) / 2;
            mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main () {
    Solution sol;
    cout << sol.firstBadVersion(size) << endl;
    return 0;
}
