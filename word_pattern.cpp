#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> pattern_to_index;      // hash a character to the first occur index
        unordered_map<string, int> str_to_index;        // hash a string to the first occur index

        // split words
        string word;
        vector<string> words;
        stringstream input(str);
        while (getline(input, word, ' '))
            words.push_back(word);

        if (words.size() != pattern.size())
            return false;

        for (int i = 0 ; i < pattern.length() ; ++i) {
            if (pattern_to_index.find(pattern[i]) == pattern_to_index.end())
                pattern_to_index[pattern[i]] = i;
            if (str_to_index.find(words[i]) == str_to_index.end())
                str_to_index[words[i]] = i;
            if (pattern_to_index[pattern[i]] != str_to_index[words[i]])
                return false;
        }
        return true;
    }
};

int main () {
    string pattern = "abba", str = "dog dog dog dog";
    Solution sol;
    cout << (sol.wordPattern(pattern, str) ? "true" : "false") << endl;
    return 0;
}
