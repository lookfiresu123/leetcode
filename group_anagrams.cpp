#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mymap;    // hash table
        for (string &str : strs) {
            // get keyword for hash
            string hash_key = str;
            sort(hash_key.begin(), hash_key.end());
            if (mymap.find(hash_key) == mymap.end())
                mymap.insert(pair<string, vector<string>>(hash_key, vector<string>(1, str)));
            else
                mymap[hash_key].push_back(str);
        }
        vector<vector<string>> ret;
        ret.reserve(strs.size());
        for (auto it = mymap.begin() ; it != mymap.end() ;++it)
            ret.push_back(it->second);
        return ret;
    }
};

int main() {
    Solution sol;
    return 0;
}
