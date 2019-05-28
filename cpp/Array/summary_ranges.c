#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 ** Return an array of size *returnSize.
 ** Note: The returned array must be malloced, assume caller calls free().
 **/

#define buf_size 30

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    int i;
    char **ranges = (char **)malloc(*returnSize * sizeof(char *));
    *returnSize = numsSize + 1;
    int *p = nums;
    int start = *p,end = *p;
    int count = 0;
    if(numsSize > 1){
        for(i=0 ; i<numsSize-1 ; i++){
            if((end = *(p+i)) != *(p+i+1)-1){
                if(start != end){
                    ranges[count] = (char *)malloc(buf_size * sizeof(char));
                    sprintf(ranges[count++],"%d->%d",start,end);
                    if(i == numsSize-2){
                        ranges[count] = (char *)malloc(buf_size * sizeof(char));
                        sprintf(ranges[count++],"%d",*(p+i+1));
                    }

                }
                else{
                    ranges[count] = (char *)malloc(buf_size * sizeof(char));
                    sprintf(ranges[count++],"%d",end);
                    if(i == numsSize-2){
                        ranges[count] = (char *)malloc(buf_size * sizeof(char));
                        sprintf(ranges[count++],"%d",*(p+i+1));
                    }
                }
                start = *(p+i+1);
                end = *(p+i+1);
            }
            else if(i == numsSize-2){
                end = *(p+i+1);
                ranges[count] = (char *)malloc(buf_size * sizeof(char));
                if(start == end)
                    sprintf(ranges[count++],"%d",end);
                else
                    sprintf(ranges[count++],"%d->%d",start,end);
            }
        }
    }
    else if(numsSize == 1){
        ranges[count] = (char *)malloc(buf_size * sizeof(char));
        sprintf(ranges[count++],"%d",end);
    }
    //ranges[count] = NULL;
    *returnSize = count;
    return ranges;
}

int main(){
    // int nums[30];
    // int numsSize,i;
    // int *returnSize = (int *)malloc(sizeof(int));
    // int temp;
    // char **ranges;
    // int count = 0;
    // printf("input for numsSize\n");
    // scanf("%d",&numsSize);
    // printf("input for nums\n");
    // for(i=0;i<numsSize;i++)
    //     scanf("%d",&nums[i]);
    // printf("input for *returnSize\n");
    // scanf("%d",&temp);
    // *returnSize = temp;
    // ranges = summaryRanges(nums,numsSize,returnSize);
    // while(ranges[count] != NULL){
    //     printf("%s ",ranges[count]);
    //     count++;
    // }
    // free(returnSize);

    int nums[] = {};
    int numsSize = sizeof(nums)/sizeof(int);
    int *returnSize = (int *)malloc(sizeof(int));
    *returnSize = 0;
    char **ranges;
    ranges = summaryRanges(nums,numsSize,returnSize);
    //printf("%s\n",ranges);

    return 0;
}
