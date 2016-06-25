class Solution {
public:
    int mySqrt(int x) {
        long long int lo = 0, hi = static_cast<long long int>(x);
        long long int ret = binary_search(static_cast<long long int>(x), lo, hi);
        return static_cast<int>(ret);
    }
private:
    long long int binary_search(long long int x, long long int lo, long long int hi) {
        if (lo <= hi) {
            long long int mid = lo + (hi-lo)/2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                return binary_search(x, lo, mid-1);
            else {
                if (mid == lo) {
                    if (hi * hi <= x)
                        return hi;
                    else
                        return lo;
                }
                else
                    return binary_search(x, mid, hi);
            }
        }
        return lo;
    }
};
