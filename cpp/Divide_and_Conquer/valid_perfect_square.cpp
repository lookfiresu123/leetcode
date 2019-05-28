#include <iostream>

using namespace std;

// 判断一个数是否是完全平方数
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1)
            return true;
        return isPerfectSquare_helper(num, 0, num);
    }
private:
    bool isPerfectSquare_helper(int num, int lo, int hi) {
        if (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            double tmp = static_cast<double>(mid);      // 使用double和除法，若使用乘法和int，有可能导致越界
            if (tmp == num / tmp)       return true;
            else if (tmp < num / tmp)   return isPerfectSquare_helper(num, mid+1, hi);
            else                        return isPerfectSquare_helper(num, lo, mid-1);
        }
        return false;
    }
};
