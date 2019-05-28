#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class Solution {
public:
    // recovery the case of letters
    vector<string> getValue(vector<string> &sentences) {
        vector<string> ret(sentences.size(), string());
        for (int i = 0 ; i < sentences.size() ; ++i) {
            string s = sentences[i];
            stringstream input(s);
            string sentence;
            while (getline(input, sentence, '.')) {
                int j = 0;
                while (sentence[j] == ' ')
                    ++j;
                sentence[j] = toupper(sentence[j]);
                ++j;
                while (j < sentence.length()) {
                    sentence[j] = tolower(sentence[j]);
                    ++j;
                }
                ret[i].append(sentence+'.');
            }
        }
        return ret;
    }
};

int main() {
    vector<string> sentences;
    string word, sentence;
    while (getline(cin, sentence)) {
        stringstream input(sentence);
        string tmp;
        while (input >> word)
            tmp.append(word+' ');
        if (!tmp.empty())   tmp.pop_back(); // delete the last ' '
        for (auto it = tmp.begin() ; it != tmp.end() ; ) {
            if (*it == ' ' && (*(it+1) == '.' || *(it+1) == ','))
                it = tmp.erase(it);
            ++it;
        }
        sentences.push_back(tmp);
    }
    Solution sol;
    vector<string> ret = sol.getValue(sentences);
    for (auto &str : ret)
        cout << str << endl;
    return 0;
}
