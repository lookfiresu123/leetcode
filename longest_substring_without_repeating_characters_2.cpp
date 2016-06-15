// 使用哈希表和双指针的方法完成longest_substring_without_repeating_characters.cpp中的问题

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lengthOfLongestSubstring(string s) {
        int cnt = 0;    // 计数值，表示有多少种字符重复了
        vector<int> vec(128, 0);    // 哈希表（字符 -> 索引），每个元素的值表示该字符在子串中出现了多少次
        int beg = 0, end = 0;   // 子串的首尾指针
        int head = 0;   // 最终子串的起始地址
        int maxlen = 0; // 最终子串的长度

        while (end < s.size()) {
            if (vec[s[end++]]++ > 0)    // 若有重复的字符，则cnt加1
                cnt++;
            while (cnt > 0)
                if (vec[s[beg++]]-- == 2)
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
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
