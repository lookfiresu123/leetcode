#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long> getValue(long n) {
        vector<long> ret;
        while (n != 1) {
            for (long i = 2 ; i <= n ; ++i) {
                // 每次循环都把部分合因子给分解成质因子
                while (n % i == 0) {
                    ret.push_back(i);
                    n /= i;
                }
            }
        }
        return ret;
    }
};

int main() {
    long n;
    Solution sol;
    vector<vector<long>> ret;
    while (cin >> n)
        ret.push_back(sol.getValue(n));
    for (auto vec : ret) {
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

