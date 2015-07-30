/*
 * create by lookfiresu123 at 2015/7/30
 *
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10000

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    /* first to promise that the bits of result can holds carry bit event */
    int result[SIZE];
    int *result_final;
    int i;
    int flag = 0;//flag of carry bits, 0 means has no carry bit, 1 means has carry bit

    if(digits[digitsSize - 1] != 9) {
        for(i = 0 ; i < digitsSize ; i++) {
            if(i == digitsSize -1)
                result[i] = digits[i] + 1;
            else
                result[i] = digits[i];
        }
        *returnSize = digitsSize;
    }
    else{
        result[digitsSize] = 0;
        flag = 1;
        for(i = digitsSize - 2 ; i >= 0 ; i--) {
            result[i+1] = digits[i] + flag;
            if(result[i+1] == 10) {
                result[i+1] = 0;
                flag = 1;
            }
            else
                flag = 0;
        }
        if(flag == 1){
            result[0] = 1;
            *returnSize = digitsSize + 1;
        }
        else {
            for(i = 0 ; i < digitsSize ; i++){
                result[i] = result[i+1];
                *returnSize = digitsSize;
            }
        }
    }
    result_final = (int *)malloc(*returnSize * sizeof(int));
    for(i = 0 ; i < *returnSize ; i++)
        result_final[i] = result[i];
    return result_final;
}

int main(void) {
    int returnSize = 0;
    int digits[] = {0};
    int digitsSize = 1;
    int *result_final = plusOne(digits,digitsSize,&returnSize);
    free(result_final);
    return 0;
}

