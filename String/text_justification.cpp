#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        vector<string> tmp;
        int remain = maxWidth, char_num = 0;
        bool flag_lastword = false;
        for (int i = 0 ; i < words.size() ; ++i) {
            if (remain > words[i].length()) {
                tmp.push_back(words[i]);
                char_num += words[i].length();
                remain -= words[i].length();
                if (i == words.size()-1) {
                    flag_lastword = true;
                    ret.push_back(adjustEachLine(tmp, maxWidth, char_num, flag_lastword));
                    tmp.clear();
                    remain = maxWidth;
                    char_num = 0;
                } else if (remain > 0)
                    --remain;
            } else {
                if (remain == words[i].length()) {
                    tmp.push_back(words[i]);
                    char_num += words[i].length();
                    remain -= words[i].length();
                } else
                    --i;
                if (i == words.size()-1)
                    flag_lastword = true;
                ret.push_back(adjustEachLine(tmp, maxWidth, char_num, flag_lastword));
                tmp.clear();
                remain = maxWidth;
                char_num = 0;
            }
        }
        return ret;
    }
private:
    string adjustEachLine(vector<string> &tmp, int maxWidth, int char_num, bool flag_lastword) {
        int space_num = maxWidth - char_num, cnt_words = tmp.size();
        string ret;
        if (cnt_words == 1) {
            ret.append(tmp[0]);
            ret.append(string(space_num, ' '));
            return ret;
        }
        if (!flag_lastword) {
            int remainder = space_num % (cnt_words - 1);
            int space_block_size = space_num / (cnt_words - 1);
            vector<string> vec(cnt_words-1, string(space_block_size, ' '));
            int i = 0;
            while (remainder-- > 0)
                vec[i++] += ' ';
            for (int i = 0 ; i < cnt_words-1 ; ++i) {
                ret.append(tmp[i]);
                ret.append(string(vec[i]));
            }
            ret.append(tmp[cnt_words-1]);
            ret.append(string(maxWidth-ret.length(), ' '));
        } else {
            for (int i = 0 ; i < cnt_words-1 ; ++i)
                ret.append(tmp[i]+' ');
            ret.append(tmp[cnt_words-1]);
            ret.append(maxWidth-char_num-cnt_words+1, ' ');
        }
        return ret;
    }
};
