#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> result;
        vector<int> order_product, reverse_product;
        vector<int>::size_type length = nums.size();
        int order_temp = 1, reverse_temp = 1;
        // 初始化
        order_product.push_back(1);
        reverse_product.push_back(1);
        // 用累积的结果填充vector
        for (vector<int>::size_type i = 0 ; i < length ; ++i) {
            order_temp *= nums[i];
            reverse_temp *= nums[length-i-1];
            order_product.push_back(order_temp);
            reverse_product.push_back(reverse_temp);
        }
        for (vector<int>::size_type i = 0 ; i < length ; ++i)
            result.push_back(order_product[i] * reverse_product[length-i-1]);
        return result;
    }
};

int main() {
    vector<int> input = {1,2,3,4};
    Solution sol;
    auto result = sol.productExceptSelf(input);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}
