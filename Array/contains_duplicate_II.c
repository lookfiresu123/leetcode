#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i,j;
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize && j<=i+k;j++){
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

int main(void){
    int nums[] = {1,2,3,1,4,5};
    int numsSize = 6;
    int k = 2;
    bool result = containsNearbyDuplicate(nums,numsSize,k);
    return 0;
}
