#include <climits>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
public:
    // 16/3 -> 16-3*(1<<2) -> 4-3*(1<<0) -> 1
    // so 16/3 = 1<<2 + 1<<0 = 5
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long dvd = labs(dividend);     // abs(INT_MIN) = INT_MAX + 1 -> overflow -> so use labs
        long long dvs = labs(divisor);

        int res = 0;

        while (dvd >= dvs) {
            long long tmp = dvs, exp = 1;
            while (dvd >= (tmp << 1)) {
                exp <<= 1;
                tmp <<= 1;
            }
            res += exp;
            dvd -= tmp;     // dvd -= dvs * exp
        }

        return sign > 0 ? res : -res;
    }
};
