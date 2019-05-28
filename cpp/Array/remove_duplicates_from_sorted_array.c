#include <stdio.h>
#include <stdlib.h>

int removeDuplicates (int *nums, int numSize) {
    int count = 0;
    int *temp = (int *)malloc(numSize * sizeof(int));
    int i;
    if (numSize == 0)
        return 0;
    temp[count++] = nums[0];
    for (i = 1 ; i < numSize ; i++)
        if (temp[count-1] != nums[i])
            temp[count++] = nums[i];
    for (i = 0 ; i < count ; i++)
        nums[i] = temp[i];
    free(temp);
    return count;
}

int main (void) {
    int nums[] = {};
    int numSize = 0;
    int result = removeDuplicates(nums, numSize);
    return 0;
}
