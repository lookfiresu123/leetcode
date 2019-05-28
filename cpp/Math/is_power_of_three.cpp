#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        double logRes = log10(n)/log10(3);
  	    return logRes == int(logRes);
    }
};

int main() {
    Solution sol;
    sol.isPowerOfThree(81);
    return 0;
}
