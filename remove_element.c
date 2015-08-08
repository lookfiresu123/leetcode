/*
 * =====================================================================================
 *
 *       Filename:  remove.element.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月08日 22时05分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int new_length;
    int *stack = (int *)malloc(numsSize * sizeof(int));
    int i;
    int j = 0;
    for(i = 0 ; i < numsSize ; i++) {
        if(nums[i] != val)
            stack[j++] = nums[i];
    }
    new_length = j;
    for(i = 0 ; i < new_length ; i++)
        nums[i] = stack[i];
    free(stack);
    return new_length;
}

int main(void) {
    int nums[] = {1,2,3,4,5};
    int numsSize = 5;
    int val = 1;
    int new_length;
    new_length = removeElement(nums,numsSize,val);
    return 0;
}
