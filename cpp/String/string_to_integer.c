#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define N 1000

int myAtoi(char* str) {
    if (! str)
        return 0;
    else {
        while (isspace(*str))
            str++;
        if (isdigit(*str) || *str == '+'|| *str == '-') {
            int sign;
            int digits[N];
            if (*str == '+') {
                str++;
                if (isdigit(*str))
                    sign = 0;   // 表示正数
                else
                    return 0;
            } else if (*str == '-') {
                str++;
                if (isdigit(*str))
                    sign = 1;   // 表示负数
                else
                    return 0;
            } else
                sign = 0;       // 表示正数
            int i = 0;
            while (isdigit(*str))
                digits[i++] = *str++ - '0';
            long sum = 0;
            int count = i;
            for (i = 0 ; i < count ; i++) {
                sum = sum * 10 + digits[i];
                if (sum > (long)INT_MAX && sign == 0)
                    return INT_MAX;
                else if (sum > (long)INT_MAX + 1 && sign == 1)
                    return INT_MIN;
            }
            if (sign == 0)
                return (int)sum;
            else
                return (int)(0 - sum);
        } else
            return 0;
    }
}

int main (void) {
    char *str = "    10522545459";
    int result = myAtoi(str);
    return 0;
}
