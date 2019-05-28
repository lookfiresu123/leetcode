#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ip;
        dfs(ret, s, ip, 0, 0);  // 深度优先搜索
        return ret;
    }
private:
    /*
     * @ret：用于保存所有可能的ip结果
     * @s：题目给定的源字符串
     * @ip：当前深度优先搜索路径的ip结果
     * @start：深度优先搜索的起始位置
     * @step：当前属于第几跳（0 <= step <= 3）
     */
    void dfs(vector<string> &ret, string &s, string ip, int start, int step) {
        int len = s.length() - start;
        if (len == 0 && step == 4) {    // 深度优先搜索的当前路径结束
            ip.erase(ip.end()-1);   // 删除最后一个'.'
            ret.push_back(ip);
            return ;
        }
        if (len > (4 - step) * 3 || len < 4 - step) // 余下的源字符串不可能组成合法的ip格式
            return ;
        int sum = 0;
        for (int i = start ; i < start + 3 ; ++i) {
            sum = sum * 10 + s[i] - '0';
            if (sum <= 255) {   // 满足条件时，才能进行下一跳的搜索
                ip += s[i];
                dfs(ret, s, ip+'.', i+1, step+1);
            }
            if (sum == 0)   // ip地址的每个分片都不会从0开始
                break;
        }
    }
};

void print(vector<string> &ret) {
    for (int i = 0 ; i < ret.size() ; ++i)
        cout << ret[i] << endl;
}

int main() {
    string s = "25525511135";
    Solution sol;
    vector<string> ret = sol.restoreIpAddresses(s);
    print(ret);
    return 0;
}
