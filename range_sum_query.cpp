#include <vector>
#include <iostream>

using namespace std;

// 利用伙伴系统存储

class NumArray {
private:
    vector<int>::size_type low_limit, high_limit;   // [1:n]
    vector<int> thousand_block, hundred_block, ten_block, one_block;
public:
    int sum_range(vector<int> &nums, vector<int>::size_type low_range, vector<int>::size_type high_range) {
        int sum = 0;
        for (vector<int>::size_type i = low_range ; i <= high_range ; ++i)
            sum += nums[i];
        return sum;
    }

    NumArray(vector<int> &nums) {
        low_limit = 0;
        high_limit = nums.size()-1;
        if (high_limit < nums.size()) {
            // 计算千块
            if (high_limit - low_limit >= 999) {
                for (vector<int>::size_type i = low_limit ; i <= high_limit - 999 ; ++i)
                    thousand_block.push_back(sum_range(nums, i, i + 999));      // 第i个千块（从0开始算起）
            }
            // 计算百块
            if (high_limit - low_limit >= 99) {
                for (vector<int>::size_type i = low_limit ; i <= high_limit - 99 ; ++i)
                    hundred_block.push_back(sum_range(nums, i, i + 99));        // 第i个百块（从0开始算起）
            }
            // 计算十块
            if (high_limit - low_limit >= 9) {
                for (vector<int>::size_type i = low_limit ; i <= high_limit - 9 ; ++i)
                    ten_block.push_back(sum_range(nums, i, i + 9));             // 第i个十块（从0开始算起）
            }
            // 计算个块
            for (vector<int>::size_type i = low_limit ; i <= high_limit ; ++i)
                one_block.push_back(nums[i]);
        }
    }

    /* 决定需要哪几个块 */
    vector<int>::size_type determine_count(vector<int> &need, vector<int>::size_type low_range, vector<int>::size_type high_range, unsigned base) {
        while ((low_range + (static_cast<vector<int>::size_type>(base) - 1)) <= high_range) {
            if (base == 1000)
                need.push_back(thousand_block[low_range]);
            else if (base == 100)
                need.push_back(hundred_block[low_range]);
            else if (base == 10)
                need.push_back(ten_block[low_range]);
            else if (base == 1)
                need.push_back(one_block[low_range]);
            low_range += base;
        }
        return low_range;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        vector<int>::size_type low_range_input = static_cast<vector<int>::size_type>(i);
        vector<int>::size_type high_range_input = static_cast<vector<int>::size_type>(j);

        vector<int>::size_type low_range = (low_range_input < low_limit ? low_limit : low_range_input);
        vector<int>::size_type high_range = (high_range_input > high_limit ? high_limit : high_range_input);

        // 决定需要哪几个千容量块，百容量块，十容量块，个容量块
        vector<int> thousand_block_need, hundred_block_need, ten_block_need, one_block_need;
        low_range = determine_count(thousand_block_need, low_range, high_range, 1000);
        low_range = determine_count(hundred_block_need, low_range, high_range, 100);
        low_range = determine_count(ten_block_need, low_range, high_range, 10);
        low_range = determine_count(one_block_need, low_range, high_range, 1);

        // 计算sum
        for (vector<int>::size_type i = 0 ; i < thousand_block_need.size() ; ++i)
            sum += thousand_block_need[i];
        for (vector<int>::size_type i = 0 ; i < hundred_block_need.size() ; ++i)
            sum += hundred_block_need[i];
        for (vector<int>::size_type i = 0 ; i < ten_block_need.size() ; ++i)
            sum += ten_block_need[i];
        for (vector<int>::size_type i = 0 ; i < one_block_need.size() ; ++i)
            sum += one_block_need[i];

        return sum;
    }
};

int main() {
    // vector<int> vec = {-8261, 2300, -1429, 6274, 9650, -3267, 1414, -8102, 6251, -5979, -5291, -4616, -4703};
    vector<int> vec;
    NumArray na(vec);
    cout << na.sumRange(9,11) << endl;
    // cout << na.sumRange(2,11) << endl;
    return 0;
}
