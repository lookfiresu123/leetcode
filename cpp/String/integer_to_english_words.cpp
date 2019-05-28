#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        vector<int> vec;
        if (num == 0)
            return "Zero";
        int tmp;
        while (num) {
            tmp = num % 1000;
            vec.push_back(tmp);
            num /= 1000;
        }
        int sz = vec.size();
        vector<string> strss;
        string ret;
        vector<string> words = {"Hundred", "Thousand", "Million", "Billion"};
        for (int i = sz-1 ; i >= 1 ; --i) {
            int a = vec[i];
            vector<string> strs;
            processInThousand(strs, a);
            if (!strs.empty())
                strs.push_back(words[i]);
            for (auto str : strs)
                strss.push_back(str);
        }
        vector<string> strs;
        processInThousand(strs, vec[0]);
        for (auto str : strs)
            strss.push_back(str);
        for (auto str : strss)
            ret.append(str + ' ');
        if (!ret.empty() && ret.back() == ' ')
            ret.pop_back();
        return ret;
    }
private:
    void processInThousand(vector<string> &strs, int num) {
        vector<int> vec(3, 0);
        int tmp;
        int i = 0;
        while (num) {
            tmp = num % 10;
            vec[i++] = tmp;
            num /= 10;
        }
        int sz = vec.size();
        vector<string> words1 = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string> words11 = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> words2 = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        for (int i = sz-1 ; i >= 0 ; --i) {
            if (i == 0 && vec[i] >= 0) {    // 个位
                if (vec[i+1] == 1)
                    strs.push_back(words11[vec[i]]);
                else if (vec[i])
                    strs.push_back(words1[vec[i]-1]);
            }
            if (i == 1 && vec[i] > 1) {    // 十位
                strs.push_back(words2[vec[i]-2]);
            }
            if (i == 2 && vec[i] > 0) {    // 百位
                strs.push_back(words1[vec[i]-1]);
                strs.push_back("Hundred");
            }
        }
    }
};

int main() {
    Solution sol;
    int num = 100000101;
    string ret = sol.numberToWords(num);
    cout << ret << endl;
    return 0;
}
