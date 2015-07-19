#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    int i,j;
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

int main(void){
    int nums[] = {1,2,3,4,1,5,6};
    int numsSize = 7;
    bool result = containsDuplicate(nums,numsSize);
    return 0;
}
