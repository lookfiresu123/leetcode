#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        string::size_type max_product = 0;
        auto length = words.size();
        if (length == 0)
            return 0;
        vector<int> temp(length, 0);  // 初始化temp，每个temp都保存对于word的字母信息（32位int的低26位用于指示该word有无对应字母，其中a对于第0位）
        for (vector<int>::size_type i = 0 ; i < length ; ++i)
            for (auto c : words[i])
                temp[i] |= 1 << (c - 'a');

        // 检查有无temp[i]和temp[j]之间有无重复字母，若没有，则计算它们的product，并和max_product比较，将较大值设为新的max_product
        for (vector<int>::size_type i = 0 ; i < length-1 ; ++i)
            for (vector<int>::size_type j = i+1 ; j < length ; ++j)
                if (((temp[i] & temp[j]) == 0) && (max_product < words[i].size() * words[j].size()))
                        max_product = words[i].size() * words[j].size();
        return static_cast<int>(max_product);
    }
};

int main() {
    Solution sol;
    // vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<string> words = {"a"};
    cout << sol.maxProduct(words) << endl;
    return 0;
}
