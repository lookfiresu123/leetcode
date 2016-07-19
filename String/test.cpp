#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        // build dictionary
        for(int i = 0; i < words.size(); i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if(dict.find("")!=dict.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == dict[""]) continue;
                if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
            }
        }

        // candidate is among the words
        // left | right | reverse(candidate) -> palindrome ?
        // reverse(candidate) | left | right -> palindrome ?
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);    // left = words[i][0:j-1], maybe empty
                string right = words[i].substr(j, words[i].size() - j); // right = words[i][j:len-1], can't be empty

                if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                    ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                }

                if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                    ans.push_back({dict[right], i});
                }
            }
        }

        return ans;
    }

    bool isPalindrome(string str){
        int i = 0;
        int j = str.size() - 1;
        while(i < j) {
            if(str[i++] != str[j--]) return false;
        }
        return true;
    }
};

int main() {
    vector<string> words = {"lls", "sssll"};
    Solution sol;
    vector<vector<int>> ret = sol.palindromePairs(words);
    return 0;
}
