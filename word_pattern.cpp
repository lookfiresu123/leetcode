#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Element {
    char p_char;    // pattern's char
    string s_str;    // str's word
    Element(char ch, string &s) : p_char(ch), s_str(s) {}
};

class Solution {
private:
    vector<Element> vec;    // 存储容器
    vector<Element> dic;    // 字典
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        string word;
        vector<char> chs;
        std::istringstream iss(str);
        while(iss >> word)
            words.push_back(word);
        // cout << words.size() << endl;   // print words's size
        for (auto i : pattern)
            chs.push_back(i);
        // cout << chs.size() << endl;     // print pattern's size
        // promise words.size() == chs.size()
        if (words.size() != chs.size())
            return false;
        else {
            // create element objects and push them into vec
            std::vector<string>::iterator iter_words;
            std::vector<char>::iterator iter_pattern;
            for (iter_words = words.begin(), iter_pattern = chs.begin() ; iter_words != words.end() ; ++iter_words, ++iter_pattern)
                vec.push_back(Element(*iter_pattern, *iter_words));
            // init dic
            std::string temp;
            for (auto i = 'a' ; i < 'z' ; ++i)
                dic.push_back(Element(i, temp));
            // 在dic中搜索，确定单射pattern -> str的正确性
            for (auto iter = vec.begin() ; iter != vec.end() ; ++iter) {
                if (dic[iter->p_char - 'a'].s_str.empty())  // 若字符串对应的位置还未被初始化
                    dic[iter->p_char - 'a'].s_str = iter->s_str;
                else {
                    if (iter->s_str != dic[iter->p_char - 'a'].s_str)
                        return false;
                }
            }
            // 在dic中搜索，确定单射str -> pattern的正确性
            vector<string> str_temp;
            for (auto iter = dic.begin() ; iter != dic.end() ; ++iter) {
                if (!iter->s_str.empty())
                    str_temp.push_back(iter->s_str);
            }
            for (auto iter1 = str_temp.begin() ; iter1 != str_temp.end()-1 ; ++iter1) {
                for (auto iter2 = iter1+1 ; iter2 != str_temp.end() ; ++iter2) {
                    if (*iter1 == *iter2)
                        return false;
                }
            }
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
