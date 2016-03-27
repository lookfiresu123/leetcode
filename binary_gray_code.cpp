#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

class Solution_1 {
public:
    void gray_helper(vector<vector<int>> &ret, vector<int> &temp, vector<int>::size_type n, bool change_last) {
        if (n > 1) {
            if (change_last)
                *temp.rbegin() ^= 1;
            else {
                vector<int>::reverse_iterator pos = find(temp.rbegin(), temp.rend(), 1);
                ++pos;
                *pos ^= 1;
            }
            ret.push_back(temp);
            gray_helper(ret, temp, --n, !change_last);
        }
    }

    vector<vector<int>> binary_gray_code(int n) {
        vector<vector<int>> ret;
        int count = 1;
        for (int i = 0 ; i < n ; ++i)
            count *= 2;
        bool change_last = true;
        vector<int> temp(n, 0);
        if (! temp.empty())
            ret.push_back(temp);
        gray_helper(ret, temp, static_cast<vector<int>::size_type>(count), change_last);
        return ret;
    }
};

class Solution_2 {
public:
    void gray_helper(deque<deque<int>> &deq, deque<deque<int>>::size_type count) {
        if (deq.size() == count)
            return ;
        if (deq.empty()) {
            deq.push_front({0});
            deq.push_front({1});
        } else {
            deque<deque<int>> temp = deq;
            auto len = deq.size();
            for (auto iter = temp.rbegin() ; iter != temp.rend() ; ++iter)
                deq.push_back(*iter);
            for (deque<deque<int>>::size_type i = 0 ; i < len ; ++i)
                deq[i].push_front(0);
            for (deque<deque<int>>::size_type i = len ; i < 2*len ; ++i)
                deq[i].push_front(1);
        }
        gray_helper(deq, count);
    }

    vector<vector<int>> binary_gray_code(int n) {
        vector<vector<int>> ret;
        deque<deque<int>> deq;
        int count = 1;
        for (int i = 0 ; i < n ; ++i)
            count *= 2;
        gray_helper(deq, static_cast<deque<deque<int>>::size_type>(count));
        for (deque<deque<int>>::size_type i = 0 ; i < deq.size() ; ++i)
            ret.push_back(vector<int>(deq[i].begin(), deq[i].end()));
        return ret;
    }

};

bool check(vector<vector<int>> &ret) {
    for (vector<vector<int>>::size_type i = 0 ; i < ret.size()-1 ; ++i) {
        vector<int> temp;
        for (vector<int>::size_type j = 0 ; j < ret[i].size() ; ++j)
            temp.push_back(ret[i][j] ^ ret[i+1][j]);
        if (count(temp.begin(), temp.end(), 1) != 1)
            return false;
    }
    return true;
}

int main() {
    // Solution_1 sol1;
    Solution_2 sol2;
    int n = 5;
    // vector<vector<int>> ret = sol1.binary_gray_code(n);
    vector<vector<int>> ret = sol2.binary_gray_code(n);
    for (vector<vector<int>>::size_type i = 0 ; i < ret.size() ; ++i) {
        for (vector<int>::size_type j = 0 ; j < ret[i].size() ; ++j)
            cout << ret[i][j];
        cout << endl;
    }
    cout << (check(ret) ? "true" : "false") << endl;
    return 0;
}
