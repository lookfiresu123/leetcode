#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct HOUSE_MONEY House_money;
struct HOUSE_MONEY {
    int index;
    int money;
};

int count = 0;      // the number of element in the index_array except -2

bool is_there_adjacent (House_money *house_money, int *index_array, int range, int value) {
    int i, temp;
    for (i = 0 ; i < range ; i++) {
        temp = house_money[value].index - house_money[index_array[i]].index;
        if (temp == -1 || temp == 1)
            return true;
    }
    return false;
}

int rob (int *nums, int numsSize){
    int result = 0;

    // build House_money list memory
    House_money *house_money = (House_money *)malloc(numsSize * sizeof(House_money));
    int i;
    for (i = 0 ; i < numsSize ; i++) {
        house_money[i].index = i;
        house_money[i].money = nums[i];
    }

    // sort this house by money from high to low;
    int max, j, temp;
    for (i = 0 ; i < numsSize ; i++) {
        // find the max between i and numSize-1
        max = i;
        for (j = i ; j < numsSize ; j++) {
            if (house_money[max].money < house_money[j].money)
                max = j;
        }
        // swap house_money[max] and house_money[i]
        temp = house_money[max].money;
        house_money[max].money = house_money[i].money;
        house_money[i].money = temp;
        temp = house_money[max].index;
        house_money[max].index = house_money[i].index;
        house_money[i].index = temp;
    }

    int *index_array = (int *)malloc(numsSize * sizeof(int));
    for (i = 0 ; i < numsSize ; i++)
        index_array[i] = -2;            // initialize this array

    // get the result
    for (i = 0 ; i < numsSize ; i++) {
        if (is_there_adjacent(house_money, index_array, count, i) == false)
            index_array[count++] = i;
    }

    // calculate the sum of money
    for (i = 0 ; i < count ; i++)
        result += house_money[index_array[i]].money;

    free(house_money);
    free(index_array);
    count = 0;  // reset count
    return result;
}

int main (void) {
    int nums[3] = { 1,3,1 };
    int numsSize = 3;
    int result = rob(nums, numsSize);
    printf("%d\n",result);
    return 0;
}
