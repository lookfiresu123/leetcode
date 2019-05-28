#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        int m = n < 0 ? 0-n : n;
        vector<int> vec1;
        int t;
        // 十进制转二进制
        while (m != 0) {
            t = m % 2;
            vec1.push_back(t);
            m /= 2;
        }
        vector<int> vec2;
        // 17 -> vec2[0] = 0, vec2[1] = 4
        for (int i = 0 ; i < vec1.size() ; ++i) {
            if (vec1[i] != 0)
                vec2.push_back(i);
        }

        double ret = 1;
        for (int i = 0 ; i < vec2.size() ; ++i) {
            double tmp = x;
            for (int j = 0 ; j < vec2[i] ; ++j)
                tmp *= tmp;
            ret *= tmp;
        }

        if (n < 0)
            ret = 1 / ret;
        return ret;
    }
};
