#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return int(sqrt(n));
    }
};

int main() {
    Solution sol;
    cout << sol.bulbSwitch(10) << endl;
    return 0;
}
