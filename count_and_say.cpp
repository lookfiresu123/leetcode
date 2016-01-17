#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string get_string(string &s) {
        int count = 1;
        vector<int> temp;
        string result;
        for (char c : s)
            temp.push_back(c - '0');
        if (temp.size() <= 1)
            result = to_string(1) + to_string(temp.front());
        else {
            for (vector<int>::size_type i = 1 ; i < temp.size() ; ++i) {
                if (temp[i] == temp[i-1])
                    ++ count;
                else {
                    result += (to_string(count) + to_string(temp[i-1]));
                    count = 1;
                }
            }
            // 记录最后一个
            result += (to_string(count) + to_string(temp[temp.size()-1]));
        }
        return result;
    }

    string countAndSay(int n) {
        // move integer to string
        string result = to_string(1);
        for (int i = 1 ; i < n ; ++i) {
            result = get_string(result);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n = 5;
    for (int i = 1 ; i <= n ; ++i)
        cout << sol.countAndSay(i) << endl;
    return 0;
}
