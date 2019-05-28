#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.empty() && s2 == s3) || (s2.empty() && s1 == s3))
            return true;
        int sz1 = s1.length(), sz2 = s2.length(), sz3 = s3.length();
        if (sz1 + sz2 != sz3)
            return false;
        // s1[i], s2[j], s3[i+j]
        vector<vector<bool>> vec(sz1+1, vector<bool>(sz2+1, false));
        int row = sz1+1, col = sz2+1;
        vec[0][0] = true;               // s1[:-1] + s2[:-1] == s3[:-1]
        for (int i = 1 ; i < row ; ++i) {
            if (s1[i-1] == s3[i-1])
                vec[i][0] = true;       // s1[:i-1] + s2[:-1] == s3[:i-1]
            else
                break;
        }
        for (int j = 1 ; j < col ; ++j) {
            if (s2[j-1] == s3[j-1])
                vec[0][j] = true;       // s1[:-1] + s2[:j-1] == s3[:j-1]
            else
                break;
        }
        for (int i = 1 ; i < row ; ++i) {
            for (int j = 1 ; j < col ; ++j) {
                // if s1[i-1], s2[j-1] != s3[i+j-1], then combination of s1[:i-1]
                // and s2[:j-1] can't produce s3[:i+j-1]
                if (s1[i-1] != s3[i+j-1] && s2[j-1] != s3[i+j-1])
                    vec[i][j] = false;

                // if s1[i-1] == s3[i+j-1], then the result of whether combination
                // of s1[:i-1] and s2[:j-1] produce s3[:i+j-1] maybe determined by the
                // result of whether combination of s1[:i-2] and s2[:j-1]
                // produce s3[:i+j-2]
                if (s1[i-1] == s3[i+j-1])
                    vec[i][j] = vec[i][j] || vec[i-1][j];

                // if s2[j-1] == s3[i+j-1], then the result of whether
                // combination of s1[:i-1] and s2[:j-1] produce s3[:i+j-1]
                // maybe detemined by the result of whether combination of s1[:i-1]
                // and s2[:j-2] produce s3[:i+j-2]
                if (s2[j-1] == s3[i+j-1])
                    vec[i][j] = vec[i][j] || vec[i][j-1];
            }
        }
        return vec[row-1][col-1];
    }
};
