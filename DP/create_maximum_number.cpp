#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        if (k <= 0)
            return ret;
        vector<string> vec;
        for (int z = 0 ; z <= k ; ++z) {
            int cnt_nums1 = z, cnt_nums2 = k - z;
            // 挑最大的有序的cnt_nums1和cnt_nums2个元素
            if (cnt_nums1 > nums1.size() || cnt_nums2 > nums2.size())
                continue;
            vector<int> tmp1, tmp2;
            selectMax(tmp1, nums1, 0, nums1.size()-1, cnt_nums1);
            selectMax(tmp2, nums2, 0, nums2.size()-1, cnt_nums2);
            // 合并
            vector<int> tmp = combination(tmp1, tmp2);
            string s;
            for (auto i : tmp)
                s += (i + '0');
            vec.push_back(s);
        }
        string max = vec[0];
        for (int i = 1 ; i < vec.size() ; ++i)
            max = max < vec[i] ? vec[i] : max;
        for (auto c : max)
            ret.push_back(c - '0');
        return ret;
    }
private:
    // 合并
    vector<int> combination(vector<int> &nums1, vector<int> &nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        int sz = sz1 + sz2;
        vector<int> tmp(sz, 0);
        for (int z = 0, i = 0, j = 0 ; z < sz ; ) {
            if (i == sz1) {
                while (j < sz2)
                    tmp[z++] = nums2[j++];
            } else if (j == sz2) {
                while (i < sz1)
                    tmp[z++] = nums1[i++];
            } else if (nums1[i] < nums2[j])
                tmp[z++] = nums2[j++];
            else if (nums1[i] > nums2[j])
                tmp[z++] = nums1[i++];
            else {
                int ki = i, kj = j;
                while (ki < sz1 && kj < sz2 && nums1[ki] == nums2[kj]) {
                    ++ki;
                    ++kj;
                }
                if (ki == sz1 && kj == sz2)
                    tmp[z++] = nums1[i++];
                else if (ki == sz1)
                    tmp[z++] = nums2[j++];
                else if (kj == sz2)
                    tmp[z++] = nums1[i++];
                else {
                    if (nums1[ki] > nums2[kj])  tmp[z++] = nums1[i++];
                    else                        tmp[z++] = nums2[j++];
                }
            }
        }
        return tmp;
    }
    
    // 挑最大的有序的cnt个元素组成vector
    void selectMax(vector<int> &tmp, vector<int> &nums, int lo, int hi, int cnt) {
        if (cnt == 0)
            return ;
        if (hi-lo+1 == cnt) {
            for (int i = lo ; i <= hi ; ++i)
                tmp.push_back(nums[i]);
            return ;
        }
        int maxpos, max = -1;
        for (int i = lo ; i <= hi-cnt+1 ; ++i) {
            if (max < nums[i]) {
                max = nums[i];
                maxpos = i;
            }
        }
        tmp.push_back(nums[maxpos]);
        selectMax(tmp, nums, maxpos+1, hi, cnt-1);
    }
};

void print(vector<int> &ret) {
    for (int i = 0 ; i < ret.size() ; ++i)
        cout << ret[i] << " ";
    cout << endl;
}

int main() {
    vector<int> nums1 = {6,7};
    vector<int> nums2 = {6,0,4};
    int k = 5;
    Solution sol;
    vector<int> ret = sol.maxNumber(nums1, nums2, k);
    print(ret);
    return 0;
}
