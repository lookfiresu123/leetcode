#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // create vecs by cin, which vecs.size() = K, vecs[i].size() = M * N
    int regChar(vector<vector<int> > &vecs) {
        if (vecs.empty())
            return 0;
        int n = vecs[0].size();
        vector<int> tmp(n, 0);
        for (int i = 0 ; i < vecs.size() ; ++i)
            implXor(tmp, vecs[i]);
        int cnt = countForOne(tmp);
        int ret = getMinPixel(cnt, vecs.size());
        return ret;
    }
private:
    // vec1.size() == vec2.size()
    void implXor(vector<int> &vec1, vector<int> &vec2) {
        int n = vec1.size();
        for (int i = 0 ; i < n ; ++i)
            vec1[i] ^= vec2[i];
    }

    int countForOne(vector<int> &vec) {
        int cnt = 0;
        for (int i = 0 ; i < vec.size() ; ++i)
            if (vec[i] == 1)
                ++cnt;
        return cnt;
    }

    int getMinPixel(int n, int K) {
        for (int i = 1 ; i <= n ; ++i) {
            int tmp = 1;
            // calculate for C(n, K)
            for (int j = n ; j > n-i ; --j)
                tmp *= j;
            for (int j = K ; j >= 1 ; --j)
                tmp /= j;
            if (tmp >= K)
                return tmp;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}
