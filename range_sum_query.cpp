#include <vector>
#include <iostream>

using namespace std;

// 利用伙伴系统存储

class NumArray {
private:
    vector<int>::size_type low_limit, high_limit;   // [1:n]
    vector<int> thousand_block, hundred_block, ten_block, one_block;
public:
    NumArray(vector<int> &nums) {
        low_limit = 1;
        high_limit = nums.size();
        int sum_thousand = 0, sum_hundred = 0, sum_ten = 0, sum_one = 0;
        // adapt , for example: A[1:1234] -> thousand_block[1:1] +
        // hundred_block[1*10+1:12] + ten_block[12*10+1:123] +
        // one_block[123*10+1:1234]
        one_block.push_back(0);
        ten_block.push_back(0);
        hundred_block.push_back(0);
        thousand_block.push_back(0);

        for (vector<int>::size_type i = low_limit ; i <= high_limit ; ++i) {
            sum_one += nums[i-1];
            sum_ten += nums[i-1];
            sum_hundred += nums[i-1];
            sum_thousand += nums[i-1];

            one_block.push_back(sum_one);
            sum_one = 0;
            if ((i % 10) == 9) {
                ten_block.push_back(sum_ten);
                sum_ten = 0;
            }
            if ((i % 100) == 99) {
                hundred_block.push_back(sum_hundred);
                sum_hundred = 0;
            }
            if ((i % 1000) == 999) {
                thousand_block.push_back(sum_thousand);
                sum_thousand = 0;
            }
        }
    }

    /* 决定需要多少块 */
    int determine_count(int low_range, int high_range, int base) {
        int count;
        if ((count = (high_range - low_range + 1) / base) > 0) {
            return count;
        } else
            return 0;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        vector<int>::size_type low_range_input = static_cast<vector<int>::size_type>(i+1);
        vector<int>::size_type high_range_input = static_cast<vector<int>::size_type>(j+1);

        vector<int>::size_type low_range = (low_range_input < low_limit ? low_limit : low_range_input);
        vector<int>::size_type high_range = (high_range_input > high_limit ? high_limit : high_range_input);

        // 计算该range需要伙伴系统中那些块
        vector<int>::size_type low_range_one_block, low_range_ten_block, low_range_hundred_block, low_range_thousand_block;
        vector<int>::size_type high_range_one_block, high_range_ten_block, high_range_hundred_block, high_range_thousand_block;

        // 决定需要多少千容量块，百容量块，十容量块，个容量块
        int count_thousand = determine_count(low_range, high_range, 1000);
        // 修改low_range和high_range
        if (count_thousand != 0) {
            low_range_thousand_block = low_range / 1000 + 1;
        }
        int count_hundred = determine_count(low_range, high_range, 100);
        // 修改low_range和high_range

        int count_ten = determine_count(low_range, high_range, 10);
        // 修改low_range和high_range

        int count_one = determine_count(low_range, high_range, 1);
        // 修改low_range和high_range


        return sum;
    }
};

int main() {
    vector<int> vec = {-8261, 2300, -1429, 6274, 9650, -3267, 1414, -8102, 6251, -5979, -5291, -4616, -4703};
    NumArray na(vec);
    cout << na.sumRange(9,11) << endl;
    // cout << na.sumRange(2,11) << endl;
    return 0;
}
