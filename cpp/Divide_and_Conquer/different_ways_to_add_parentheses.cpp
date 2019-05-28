#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (string::size_type i=0; i<input.size(); ++i) {
            char c = input[i];
            if (ispunct(c))
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
        }
        return output.size() ? output : vector<int>{stoi(input)};
    }
};

int main() {
    string str = "1*2-3+4";
    Solution sol;
    vector<int> ret = sol.diffWaysToCompute(str);
    for_each(ret.begin(), ret.end(), [](int x){ cout << x << endl;});
    return 0;
}
