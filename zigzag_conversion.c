#include<stdio.h>
#include<stdlib.h>

/*
 * 0       8           16
 * 1     7 9        15 17
 * 2   6   10    14    18
 * 3 5     11 13       19
 * 4       12          20
 *
 * (0,8,16),(1,7,9,15,17),(2,6,10,14,18),(3,5,11,13,19),(4,12,20)
 *
 * left     right
 *   0        8
 *   1        7
 *   2        6
 *   3        5
 *   4        4
 * */

char* convert(char* s, int numRows) {
    if(!s)
        return NULL;
    /* calculate the length of s */
    int length_s = 0;
    while(s[length_s])
        length_s++;
    if(length_s == 0)
        goto out;
    int count = 0;
    char *result = (char *)malloc((length_s+1) * sizeof(char));
    if(numRows == 1){
        while(count < length_s){
            result[count] = s[count];
            count++;
        }
        goto out;
    }
    int i = 0;
    int j = 0;
    //int sum = 0;
    int gap = 2 * (numRows - 1);
    int left = 0;
    int right = gap;
    int step_1;
    int step_2;
    int temp;
    while(left <= right){
        result[j++] = s[i];
        step_1 = right - left;
        step_2 = gap - step_1;
        temp = i;
        while(temp < length_s){
            if(step_1 == 0 && step_2 == 0)
                break;
            if(step_1 != 0){
                temp += step_1;
                if(temp >= length_s)
                    break;
                result[j++] = s[temp];
            }
            if(step_2 != 0){
                temp += step_2;
                if(temp >= length_s)
                    break;
                result[j++] = s[temp];
            }
        }
        left++;
        right--;
        i++;
        if(i == length_s)
            break;
    }
out:
    result[length_s] = '\0';
    return result;
}

int main(void){
    char *result;
    char *s = "PAYPALISHIRING";
    int numRows = 1;
    result = convert(s,numRows);
    free(result);
    return 0;
}
