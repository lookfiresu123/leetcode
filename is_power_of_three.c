#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool isPowerOfThree (int n) {
    if (n < 3) {
        if (n == 1)
            return true;
        else
            return false;
    } else {
        int quotient = n;
        int remainder = 0;
        while (quotient >= 3) {
            remainder = quotient % 3;
            quotient /= 3;
            if (remainder != 0)
                return false;
            if (quotient == 1 && remainder == 0)
                return true;
        }
    }
    return false;
}


int main (void) {
    int n = 81;
    if(isPowerOfThree(n) == true)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
