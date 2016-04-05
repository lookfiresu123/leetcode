#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Coder {
public:
    vector<string> findCoder(vector<string> A, int n) {
        // write code here
        int max_sz = 0;
        for (auto str : A)
            max_sz = max_sz > str.size()/5 ? max_sz : str.size()/5;
        vector<vector<string>> vec(max_sz, {""});
        vector<string> rret;
        string t = "coder";
        for (auto str : A) {	// 遍历A
            int cnt = 0;
            string s;
            // 转换大小写
			for (auto c : str)
                s.push_back(tolower(c));
            // 查找
            auto it = s.begin();
            while ( (it = search(it, s.end(), t.begin(), t.end())) != s.end() ) {
                ++cnt;
                ++it;
            }
            if (cnt)
            	vec[cnt].push_back(str);
        }
        for (auto v : vec) {
			while (v.back() != "") {
                rret.push_back(v.back());
                v.pop_back();
            }
        }
        vector<string> ret(rret.rbegin(), rret.rend());
        return ret;
    }
};

int main() {
    vector<string> vec = {"i am a coder","Coder Coder","Code"};
    Coder co;
    vector<string> ret = co.findCoder(vec, vec.size());
    for_each(ret.begin(), ret.end(), [](string &s){ cout << s << endl; });
    return 0;
}
