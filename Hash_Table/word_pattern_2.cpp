#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vec;
        stringstream input(str);
        string word;
        while (input >> word)
            vec.push_back(word);
        if (pattern.size() != vec.size())
            return false;

        vector<pair<string, int>> hash_array_str(capacity, pair<string, int>("", -1));   // hash table for str
        vector<int> hash_array_char(128, -1);       // hash table for char
        // initialize hash_array_char
        for (int i = 0 ; i < static_cast<int>(pattern.length()) ; ++i)
            if (hash_array_char[pattern[i]] == -1)
                hash_array_char[pattern[i]] = i;

        // initialize hash_array_str and compare with hash_array_char
        for (int i = 0 ; i < static_cast<int>(pattern.length()) ; ++i)
            if (hash_array_char[pattern[i]] != hash_function_str(vec[i], hash_array_str, i))
                return false;

        return true;
    }
private:
    static const int capacity = 10007;
    static const int mod = 10007;

    int hash_function_str(const string &key, vector<pair<string, int>> &hash_array, int index) {
        // prehash function
        unsigned int seed = 131, hash = 0;
        for (const char &c : key)
            hash = hash * seed + c;
        hash &= 0x7FFFFFFF;
        // hash function
        int pos = hash % mod;
        // hash hit
        while (hash_array[pos].second != -1 && hash_array[pos].first != key)
            pos = (pos + 10) % mod;
        if (hash_array[pos].second == -1) {
             hash_array[pos].first = key;
             hash_array[pos].second = index;
        }
        return hash_array[pos].second;
    }
};

int main() {
    string pattern = "ab";
    string str = "b c";
    Solution sol;
    cout << (sol.wordPattern(pattern, str) ? "true" : "false") << endl;
    return 0;
}
