#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n) {
    if (nums2 != NULL && n != 0) {
        int length = m + n;
        int *temp = (int *)malloc(length * sizeof(int));
        int i, i_1, i_2;
        for (i = 0, i_1 = 0, i_2 = 0 ; i < length && i_1 < m && i_2 < n; i++) {
            if (nums1[i_1] <= nums2[i_2])
                temp[i] = nums1[i_1 ++];
            else
                temp[i] = nums2[i_2 ++];
        }
        if (i_1 == m) {
            // fill temp by nums2
            while (i_2 < n)
                temp[i ++] = nums2[i_2 ++];
        } else {
            // fill temp by nums1
            while (i_1 < m)
                temp[i ++] = nums1[i_1 ++];
        }
        // copy temp to nums1
        for (i = 0 ; i < length ; i++)
            nums1[i] = temp[i];
        free(temp);
    }
}

int main (void) {
    int nums1[100] = {1,3,5,7};
    int nums2[100] = {2,4,6,8};
    merge(nums1, 4, nums2, 4);
    return 0;
}
