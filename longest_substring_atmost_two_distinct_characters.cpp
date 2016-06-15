#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lengthOfLongestSubstringTwoDistinct(string s) {
        int maxlen = 0;
        int beg = 0, end = 0;   // 两个指针，表示子串的首尾
        int head = 0;           // 最终子串的首地址
        int cnt = 0;            // 子串中不同字符的个数
        vector<int> vec(128, 0);    // 哈希表（字符 -> 索引）
        while (end < s.size()) {
            if (vec[s[end++]]++ == 0)   // 若该字符在子串中还未出现过，则令cnt加1
                cnt++;
            while (cnt > 2)
                if (vec[s[beg++]]-- == 1)  // 使子串有效（即从子串中消除某种字符）
                    cnt--;
            if (end - beg > maxlen)
                maxlen = end - (head = beg);
        }
        return maxlen == 0 ? "" : s.substr(head, maxlen);
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}
