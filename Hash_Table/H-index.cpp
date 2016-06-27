#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getnum(vector<int>& citations, int i) {
        int cnt = count_if(citations.begin(), citations.end(), [&i](int x){ return x >= i; });
        return cnt;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        if (citations.empty())
            return 0;
        int i = 0;
        while (true) {
            if (getnum(citations, i) < i)
                break;
            ++i;
        }
        return i-1;
    }
};
