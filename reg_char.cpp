#include <vector>
#include <iostream>
#include <string>

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
    // implement the xor operator, and vec1.size() == vec2.size()
    void implXor(vector<int> &vec1, vector<int> &vec2) {
        int n = vec1.size();
        for (int i = 0 ; i < n ; ++i)
            vec1[i] ^= vec2[i];
    }

    // count the number of 1 in vec
    int countForOne(vector<int> &vec) {
        int cnt = 0;
        for (int i = 0 ; i < vec.size() ; ++i)
            if (vec[i] == 1)
                ++cnt;
        return cnt;
    }

    // this function is used to get the minimun pixel
    // @n: the number of 1 in vec which calculated by countForOne()
    // @K: the input data K
    int getMinPixel(int n, int K) {
        for (int i = 0 ; i <= n ; ++i) {
            // tmp = 2 ** i
            int tmp = 1;
            for (int j = 0 ; j < i ; ++j)
                tmp *= 2;
            if (tmp >= K)
                return i;
        }
    }
};

int main() {
    // input data
    int N, M, K;
    cin >> N >> M >> K;
    // use pointer here, because the limit size of stack is 8M and the maximum data is 256 MB
    vector<vector<int> > *vecs_ptr = new vector<vector<int> >(K, vector<int>(N * M, 0));
    string word, data;
    while (getline(cin, word))
        if (! word.empty())
            data.append(word);
    // process data
    int sz = N * M;
    for (int i = 0 ; i < data.size() ; ++i)
        (*vecs_ptr)[i / sz][i % sz] = data[i] - '0';
    // implment data
    Solution sol;
    cout << sol.regChar(*vecs_ptr) << endl;
    delete vecs_ptr;
    return 0;
}
