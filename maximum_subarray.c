#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxSubArray (int *nums, int numsSize) {
    int sum = 0;
    int max = INT_MIN;
    int i;
    for (i = 0 ; i < numsSize ; i++) {
        sum += nums[i];
        if (sum >= max)     // 更新max
            max = sum;
        if (sum < 0)        // 当sum < 0时，丢弃之前的部分
            sum = 0;
    }
    return max;
}

int main (void) {
    //int nums[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int nums[] = { 8, -19, 5, -4, 20 };
    //int nums[] = { -2, -1 };
    int numsSize = 5;
    int sum = maxSubArray(nums, numsSize);
    printf("%d\n", sum);
    return 0;
}
