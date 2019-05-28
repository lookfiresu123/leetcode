#include <algorithm>
#include <iterator>
#include <string>
#include <array>
#include <iostream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        string result;
        int count_bulls = 0, count_cows = 0;
        array<int, 10> temp_guess, temp_secret;
        // init temp_guess , temp_secret
        for (array<int, 10>::size_type i = 0 ; i < temp_guess.size() ; ++i)
            temp_guess[i] = 0;
        for (array<int, 10>::size_type i = 0 ; i < temp_secret.size() ; ++i)
            temp_secret[i] = 0;
        // bulls：数值和位置都匹配
        // secret和guess的公共部分 - bulls
        // 计算bulls
        for (auto iter_guess = guess.begin() , iter_secret = secret.begin() ; iter_guess != guess.end() ; ++iter_guess, ++iter_secret)
            if (*iter_guess == *iter_secret)
                ++ count_bulls;
        // 计算公共部分
        for (auto c : guess)
            ++temp_guess[c - '0'];
        for (auto c : secret)
            ++temp_secret[c - '0'];
        for (array<int, 10>::size_type i = 0 ; i < temp_guess.size() ; ++i)
            count_cows += (temp_guess[i] < temp_secret[i] ? temp_guess[i] : temp_secret[i]);
        count_cows -= count_bulls;
        result = to_string(count_bulls) + "A" + to_string(count_cows) + "B";
        return result;
    }
};

int main() {
    Solution sol;
    string secret = "11", guess = "11";
    cout << sol.getHint(secret, guess) << endl;
    return 0;
}
