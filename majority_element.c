#include<stdio.h>
#include<stdlib.h>

int majorityElement(int* nums, int numsSize) {
    int result;
    int i,j;
    int sum = 0;
    int store;
    int length = numsSize;
    while(sum <= numsSize/2){
        j = 0;
        store = nums[0];
        for(i=0;i<length;i++){
            if(nums[i] == store)
                sum++;
            else
                nums[j++] = nums[i];
        }
        length = j;
    }
    result = store;
    return result;
}

int main(void){
    int nums[] = {1,2,3,1,1,3,1,1,1,4,2};
    int numsSize = 11;
    int result = majorityElement(nums,numsSize);
    return 0;
}
