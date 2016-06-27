#include <stdlib.h>
#include <time.h>

void sortColors(int* nums, int numsSize) {
    int i, j, count = 0;
    int *temp = (int *)malloc(numsSize * sizeof(int));
    for (i = 0 ; i < 3 ; i++) {
        for (j = 0 ; j < numsSize ; j++) {
            if (nums[j] == i)
                temp[count++] = nums[j];
        }
    }
    for (i = 0 ; i < numsSize ; i++)
        nums[i] = temp[i];
    free(temp);
}

/*
void sortColors(int *nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int i, temp, flag_left = 0, flag_right = 0;
    for (i = 0 ; i < 3 ; i++) {
        while (left <= right) {
            if (nums[left] == i)
                left++;
            else
                flag_left = 1;
            if (nums[right] != i)
                right--;
            else
                flag_right = 1;
            if (flag_left == 1 && flag_right == 1) {
                // swap
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                // reset flag
                flag_left = 0;
                flag_right = 0;
            }
        }
        right = numsSize - 1;
    }
}
*/
int main (void) {
    int numsSize = 1000;
    int *nums = (int *)malloc(numsSize * sizeof(int));
    int i;
    srand((unsigned)time(NULL));
    for (i = 0 ; i < numsSize ; i++)
        nums[i] = rand() % 3;
    clock_t start = clock();
    sortColors(nums, numsSize);
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    free(nums);
    return 0;
}
