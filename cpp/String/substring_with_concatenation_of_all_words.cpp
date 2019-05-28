#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // time cost : O(6*n)
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || words[0].empty() || s.length() < words[0].length()) {
            vector<int> ret;
            return ret;
        }
        vector<int> ret;
        unordered_map<string, int> hash;    // { word, count }
        for (auto str : words)
            hash[str]++;

        int wSize = words[0].length();      // every word's size

        for (int start = 0 ; start < wSize; ++start) {
            unordered_map<string, int> slidingWindow;   // {word, count}
            int wCnt = 0;
            for (int i = start ; i + wSize <= s.length() ; i += wSize) {
                string word = s.substr(i, wSize);
                if (hash.find(word) == hash.end()) {    // if there is a word which is not exist in hash, clear the sliding window
                    slidingWindow.clear();
                    wCnt = 0;
                } else {
                    slidingWindow[word]++;
                    wCnt++;
                    while (hash[word] < slidingWindow[word]) {
                        string removeWord = s.substr(i - (wCnt - 1) * wSize, wSize);
                        slidingWindow[removeWord]--;
                        wCnt--;
                    }
                }
                if (wCnt == words.size())
                    ret.push_back(i - (wCnt - 1) * wSize);  // push the start index to ret
            }
        }
        return ret;
    }
};
