#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPowerOfTwo(int n) {
    int quotient = n;
    int remainder = 0;
    while(remainder = quotient % 2, quotient /= 2, remainder == 0 && quotient != 0)
        ;
    if(remainder == 1 && quotient == 0)
        return true;
    return false;
}

int main(void){
    int n;
    while(1){
        printf("enter a non-negetive number!\n");
        scanf("%d",&n);
        if(n < 0)
            break;
        if(isPowerOfTwo(n))
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
