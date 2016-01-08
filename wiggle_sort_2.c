#include <stdlib.h>

void wiggleSort(int *nums, int numsSize) {
    /* sort the whole data */
    int i, j, min_index;
    int *temp = (int *)malloc(numsSize * sizeof(int));
    int swap_temp;
    for (i = 0 ; i < numsSize ; i++) {
        // find the min and put it in the position i
        min_index = i;
        for (j = i ; j < numsSize ; j++) {
            if (nums[min_index] > nums[j]) {
                min_index = j;
            }
        }
        // swap the value of i and min_index
        swap_temp = nums[min_index];
        nums[min_index] = nums[i];
        nums[i] = swap_temp;
    }
    // divide into two parts
    int divide_line;
    int count = 0;
    if (numsSize % 2 == 0) {
        divide_line = numsSize / 2;
        for (i = 0, j = divide_line ; j < numsSize ; i++, j++) {
            temp[count++] = nums[i];
            temp[count++] = nums[j];
        }
    } else {
        divide_line = numsSize / 2 + 1;
        for (i = 0, j = divide_line ; j < numsSize ; i++, j++) {
            temp[count++] = nums[i];
            temp[count++] = nums[j];
        }
        temp[count++] = nums[divide_line - 1];
    }
    // copy temp to nums
    for (i = 0 ; i < numsSize ; i++)
        nums[i] = temp[i];
    free(temp);
}

int main (void) {
    int nums[7] = {3,1,5,1,1,6,4};
    wiggleSort(nums, 7);
    return 0;
}
