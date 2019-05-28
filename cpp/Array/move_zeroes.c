/*
 * =====================================================================================
 *
 *       Filename:  move_zeroes.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月26日 16时04分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    // set four pointers -- left, right, start, stop
    int *left = nums;
    int *right = nums + numsSize - 1;
    int *limit_max = right;
    int *limit_min = left;
    int count;
    int *p;
    int i;

    // find the rightest pointer whose right numbers are all 0
    while (right >= limit_min && *right == 0)
        right --;
    while (1) {
        count = 0;
        // once left catch 0, stop
        while (left <= limit_max && *left != 0)
            left ++;
        if (left > right)
            break;
        // move the continuously count 0 to the right
        while (! *(left + count))
            count ++;
        p = left + count;
        while (p <= right) {
            *(p - count) = *p;
            p ++;
        }
        for (i = count-1 ; i >= 0 ; i--)
            *(right - i) = 0;

        right -= count;
    }
}

int main (void) {
    int nums[] = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    int numsSize = 10;
    moveZeroes(nums, numsSize);
    return 0;
}

