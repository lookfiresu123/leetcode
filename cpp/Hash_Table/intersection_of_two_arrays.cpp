#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if (nums1.empty() || nums2.empty())
            return ret;

        // sort nums1 and nums2
        quickSort(nums1);
        quickSort(nums2);

        // unique nums1 to tmp1, and nums2 to tmp2
        vector<int> tmp1, tmp2;
        tmp1.reserve(nums1.size()), tmp2.reserve(nums2.size());
        tmp1.push_back(nums1[0]), tmp2.push_back(nums2[0]);
        for (int i = 1 ; i < nums1.size() ; ++i)
            if (nums1[i] != nums1[i-1])
                tmp1.push_back(nums1[i]);
        for (int i = 1 ; i < nums2.size() ; ++i)
            if (nums2[i] != nums2[i-1])
                tmp2.push_back(nums2[i]);

        // search element of tmp1 in tmp2
        for (int i = 0, j = 0 ; i < tmp1.size() ; ++i) {
            if (j >= tmp2.size())
                break;
            for (int k = j ; k < tmp2.size() ; ++k) {
                if (tmp1[i] == tmp2[k]) {   // if tmp1[i] == tmp2[k], push and update j, then break;
                    ret.push_back(tmp1[i]);
                    j = k+1;
                    break;
                } else if (tmp1[i] < tmp2[k]) { // if tmp1[i] < tmp2[k], just update j, then break;
                    j = k;
                    break;
                } else if (k == tmp2.size()-1 && tmp1[i] > tmp2[k]) {   // if tmp1[i] > all element of tmp2, then jump out the search statement
                    j = k+1;
                    break;
                }
            }
        }
        return ret;
    }
private:
    void quickSort(vector<int> &vec) {
        int lo = 0, hi = vec.size()-1;
        quickSort_helper(vec, lo, hi);
    }

    void quickSort_helper(vector<int> &vec, int lo, int hi) {
        if (lo < hi) {
            int l = lo, r = hi+1;
            int base = vec[lo];
            while (true) {
                while (l < hi && vec[++l] < base) ;
                while (r > lo && vec[--r] >= base) ;
                if (r <= l) break;
                swap(vec, l, r);
            }
            swap(vec, lo, r);
            quickSort_helper(vec, lo, r-1);
            quickSort_helper(vec, r+1, hi);
        }
    }

    void swap(vector<int> &vec, int i, int j) {
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }
};

void print(vector<int> &vec) {
    for (int i = 0 ; i < vec.size() ; ++i)
        cout << vec[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {1,2,2,3,7};
    vector<int> arr2 = {2,2,8};
    Solution sol;
    vector<int> ret = sol.intersection(arr1, arr2);
    print(ret);
    return 0;
}
