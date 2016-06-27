#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void clone(vector<int> &result, int product) {
        auto sz = result.size();
        for (vector<int>::size_type i = sz ; i > 0 ; --i)
            result.push_back(result[i-1] + product);
    }

    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 0, product = 1 ; i < n ; ++i, product *= 2)
            clone(result, product);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> result = sol.grayCode(2);
    for (vector<int>::size_type i = 0 ; i < result.size() ; ++i)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
