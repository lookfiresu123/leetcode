#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Given an array S of n integers, are there elements a, b, c, and d in S such
// that a + b + c + d = target? Find all unique quadruplets in the array which
// gives the sum of target.
// Note: The solution set must not contain duplicate quadruplets.
class Solution {
public:
    typedef unordered_multimap<int, pair<vector<int>::size_type, vector<int>::size_type>> type_mymap;  // {sum, {i, j}} that nums[i]+nums[j] = sum

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4)
            return ret;

        type_mymap mymap;

        for (vector<int>::size_type i = 0 ; i < nums.size()-1 ; ++i) {
            for (vector<int>::size_type j = i+1 ; j < nums.size() ; ++j) {
                int sum = nums[i]+ nums[j];
                pair<type_mymap::iterator, type_mymap::iterator> pit = mymap.equal_range(target - sum);
                for (type_mymap::iterator it = pit.first ; it != pit.second ; ++it) {
                    if (it->second.first == i || it->second.second == i || it->second.first == j || it->second.second == j) // 忽略重复的数
                        continue;
                    // 构造四元组，并将其导入路径集中
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[it->second.first]);
                    tmp.push_back(nums[it->second.second]);
                    ret.push_back(tmp);
                }
                mymap.insert(pair<int, pair<int, int>>(sum, pair<int, int>(i, j)));
            }
        }

        // 去掉重复的数
        for (auto &m1 : ret)
            sort(m1.begin(), m1.end());
        auto it = unique(ret.begin(), ret.end());
        ret.erase(it, ret.end());

        return ret;
    }

    void print(vector<vector<int>> &ret) {
        for (vector<vector<int>>::size_type i = 0 ; i < ret.size() ; ++i) {
            for (vector<int>::size_type j = 0 ; j < ret[i].size() ; ++j)
                cout << ret[i][j] << " ";
            cout << endl;
        }
    }
};

class Solution_Advance {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ret;
        // 若nums中元素的个数小于4，则直接返回ret
        if (nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());     // 对nums排序

        // 若min(nums) > target/4 或 max(nums) < target/4，则直接返回ret
        int min = nums[0];
        int max = nums[nums.size()-1];
        if (4 * min > target && 4 * max < target)
            return ret;

        // 循环遍历
        for (vector<int>::size_type i = 0 ; i < nums.size()-3 ; ++i) {
            int z = nums[i];
            // 去掉重复的情况
            if (i > 0 && z == nums[i-1])
                continue;

            // z太小
            if (z + 3 * max < target)
                continue;

            // z太大
            if (4 * z > target)
                continue;

            threeSum(nums, target-z, i+1, nums.size()-1, ret, z);
        }

        return ret;
    }

    void print(vector<vector<int>> &ret) {
        for (vector<vector<int>>::size_type i = 0 ; i < ret.size() ; ++i) {
            for (vector<int>::size_type j = 0 ; j < ret[i].size() ; ++j)
                cout << ret[i][j] << " ";
            cout << endl;
        }
    }

private:
    void threeSum(vector<int> &nums, int target, vector<int>::size_type lo,
            vector<int>::size_type hi, vector<vector<int>> &ret, int z1) {
        auto sz = hi - lo + 1;
        if (sz < 3)
            return ;
        int min = nums[lo];
        int max = nums[hi];
        if (3 * min > target && 3 * max < target)
            return ;

        // 循环遍历
        for (vector<int>::size_type i = lo ; i < hi-1 ; ++i) {
            int z = nums[i];
            // 去掉重复的情况
            if (i > lo && z == nums[i-1])
                continue;

            // z太小
            if (z + 2 * max < target)
                continue;

            // z太大
            if (3 * z > target)
                continue;

            twoSum(nums, target-z, i+1, hi, ret, z1, z);
        }
    }

    void twoSum(vector<int> &nums, int target, vector<int>::size_type lo,
            vector<int>::size_type hi, vector<vector<int>> &ret, int z1, int z2) {
        auto sz = hi - lo + 1;
        if (sz < 2)
            return ;
        int min = nums[lo];
        int max = nums[hi];
        if (2 * min > target && 2 * max < target)
            return ;

        // 循环遍历
        for (vector<int>::size_type i = lo ; i < hi ; ++i) {
            int z = nums[i];
            // 去掉重复的情况
            if (i > lo && z == nums[i-1])
                continue;

            // z太小
            if (z + 2 * max < target)
                continue;

            // z太大
            if (2 * z > target)
                continue;

            for (vector<int>::size_type j = i+1 ; j <= hi ; ++j) {
                // 去掉重复的情况
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;

                if (z + nums[j] == target) {
                    vector<int> tmp;
                    tmp.push_back(z1);
                    tmp.push_back(z2);
                    tmp.push_back(z);
                    tmp.push_back(nums[j]);
                    ret.push_back(tmp);
                }
            }
        }
    }
};


int test_solution(vector<int> &vec, int target) {
    Solution sol;
    vector<vector<int>> ret = sol.fourSum(vec, target);
    sol.print(ret);
    return 0;
}

int test_solution_advance(vector<int> &vec, int target) {
    Solution_Advance sol;
    vector<vector<int>> ret = sol.fourSum(vec, target);
    sol.print(ret);
    return 0;
}

int main() {
    vector<int> vec = {5,5,3,5,1,-5,1,-2};
    int target = 4;
    test_solution(vec, target);
    return 0;
}
