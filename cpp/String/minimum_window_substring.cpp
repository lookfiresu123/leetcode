#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    // 实际上是一种字符串中查找特殊子串的问题
    // 该算法的时间复杂度为Theta(n)
    string minWindow(string s, string t) {
        vector<int> vec(128, 0);    // 哈希表（用于将字符值转换为索引，即'A' -> vec(ASCII('A'))）
        for (auto c : t)            // 初始化哈希表，哈希表中的每个元素存储该关键字出现的次数
            vec[c]++;
        int cnt = t.size();         // 计数值，用于检查子串是否有效
        int beg = 0, end = 0;       // 两个指针，分别指向子串的首尾
        int minlen = INT_MAX;       // 子串的最小长度
        int head = 0;               // 最终子串的起始地址
        while (end < s.size()) {    // 遍历主字符串s
            if (vec[s[end++]]-- > 0)    // 修改计数值（只有该字符还需要，其哈希值才会大于0）
                cnt--;
            while (cnt == 0) {          // 子串满足的条件（当不再需要任何字符时）
                if (end - beg < minlen) // 更新最小子串的长度和起始地址
                    minlen = end - (head = beg);
                if (vec[s[beg++]]++ == 0)   // 增加beg的值使得子串再次无效
                    cnt++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(head, minlen); // 返回子串
    }
};

int main() {
    string s, t;
    Solution sol;
    cin >> s >> t;
    cout << sol.minWindow(s, t) << endl;
    return 0;
}
