#include<stdio.h>
#include<stdlib.h>

int trailingZeroes(int n) {
    /* the nums_two must larger or equal to nums_five in n!  */
    /* 1 * 2 * 3 * 4 * 5 * ...... * 5k * . * n (n< 5(k+1))
     * */
    int nums_five = 0;
    int k = n;
    int result = 0;
    //result = nums_two <= nums_five ? nums_two : nums_five;
    while(k /= 5, nums_five += k,k != 0)
        ;
    result = nums_five;
    return result;
}

int main(void){
    int result;
    int n = 26;
    result = trailingZeroes(n);
    return 0;
}
