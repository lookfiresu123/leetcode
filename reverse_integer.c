#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LIMIT 214748364
#define LIMIT_min -2147483648

int reverse(int x) {
    int result = 0;
    int store = x;
    /* deal with positive */
    if(x >= 0){
        /* deal with reversed integer overflow */
        while(x != 0){
            if((result > LIMIT) && (x % 10 != 0))
                return 0;
            else if((result == LIMIT) && (x % 10 > 4))
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
    }
    /* deal with negetive */
    else{
        if(x == LIMIT_min)
            return 0;
        x = 0 - x;//can not deal with -2134483648
        /* deal with reversed integer overflow */
        /* because the min of int is -2147483648,
         * then the x should be -8463847412,
         * that is impossible,
         * so just do the same as positive in overflow
         * */
        while(x != 0){
            if((result > LIMIT) && (x % 10 != 0))
                return 0;
            else if((result == LIMIT) && (x % 10 > 4))
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        result = 0 - result;
    }

    return result;
}

int main(void){
    int x = -2147483648;
    int result = reverse(x);
    return 0;
}
