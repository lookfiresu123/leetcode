#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.length()+1, sz2 = word2.length()+1;
        vector<vector<int>> vec(sz1, vector<int>(sz2, 0));

        /* empty -> non-empty or non-empty -> empty or empty -> empty */
        // word1[0..i-1] -> word2[0..-1] = ""
        for (int i = 0 ; i < sz1 ; ++i)
            vec[i][0] = i;      // delete word1[0..i-1]
        // word1[0..-1] -> word2[0..j-1] = ""
        for (int j = 0 ; j < sz2 ; ++j)
            vec[0][j] = j;      // insert word2[0..j-1]

        /* non-empty -> non-empty*/
        // when word1[i-1] != word2[j-1], we have three choices
        // first, modify: word1[0..i-2] -> word2[0..j-2], then word1[i-1] -> word2[j-1]
        // second, delete: word1[0..i-2] -> word2[0..j-1], then delete word1[i-1]
        // third, insert: word1[0..i-1] -> word2[0..j-2], then insert word2[j-1]
        // use the smallest steps among these three method
        for (int i = 1 ; i < sz1 ; ++i) {
            for (int j = 1 ; j < sz2 ; ++j) {
                if (word1[i-1] == word2[j-1])   vec[i][j] = vec[i-1][j-1];
                else                            vec[i][j] = getMin(vec[i-1][j-1], vec[i][j-1], vec[i-1][j]) + 1;
            }
        }
        return vec[sz1-1][sz2-1];
    }
private:
    int getMin(int x, int y, int z) {
        int ret;
        ret = x < y ? x : y;
        ret = ret < z ? ret : z;
        return ret;
    }
};
