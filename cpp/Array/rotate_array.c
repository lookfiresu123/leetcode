#include<stdio.h>
#include<stdlib.h>

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if(k == 0)
        k = numsSize;
    //reverse all the nums
    int *left = &nums[0];
    int *right = &nums[numsSize-1];
    int temp;
    while(left<right){
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    //reverse the left nums
    left = &nums[0];
    right = &nums[k-1];
    while(left<right){
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    //reverse the right nums
    left = &nums[k];
    right = &nums[numsSize-1];
    while(left<right){
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main(void){
    int nums[] = {1,2,3,4,5,6,7};
    int numsSize = 7;
    int k = 7;
    rotate(nums,numsSize,k);
    return 0;
}
