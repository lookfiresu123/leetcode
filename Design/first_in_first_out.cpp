#include <deque>
#include <vector>
#include <iostream>
 
using namespace std;
 
class Solution {
public:
    int getValue(int n, vector<int> &vec) {
        int cnt = 0;
        int m = vec.size();
        deque<int> dq;
        for (int i = 0 ; i < m ; ++i) {
            if (!isExist(dq, vec[i])) {
                cnt++;
                if (dq.size() == n)
                    dq.pop_front();
                dq.push_back(vec[i]);
            }
        }
        return cnt;
    }
private:
    bool isExist(deque<int> dq, int val) {
        for (int i = 0 ; i < dq.size() ; ++i)
            if (dq[i] == val)
                return true;
        return false;
    }
};
 
int main() {
    int n, m;
    Solution sol;
    vector<int> ret;
    while (cin >> n) {
        cin >> m;
        vector<int> vec(m, 0);
        for (int i = 0 ; i < m ; ++i)
            cin >> vec[i];
        ret.push_back(sol.getValue(n, vec));
    }
    for (auto i : ret)
        cout << i << endl;
    return 0;
}
