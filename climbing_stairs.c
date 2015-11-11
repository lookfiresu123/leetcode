/* f(n) = f(n-1) + f(n-2), f(0) = f(1) = 1 ,f(2) = 2 */
// 这不完全是斐波那契数列，因为参数的n实际上指的是斐波那契数列里的n+1，因此要先用m=n+1，然后将m代入公式
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int climbStairs (int n) {
    int m = n + 1;
    if (m == 1 || m == 2)
        return 1;
    else {
        double constant_A = (1 + sqrt(5)) / 2;
        double constant_B = (1 - sqrt(5)) / 2;
        double constant_C = 1 / sqrt(5);
        double result = constant_C * (pow(constant_A, m) - pow(constant_B, m));
        return (int)result;
    }
}

int main (void) {
    int n = 44;
    int result = climbStairs(n);
    printf("%d\n",result);
    return 0;
}
