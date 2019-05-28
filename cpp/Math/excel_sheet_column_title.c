#include<stdio.h>
#include<stdlib.h>

#define length 1000
#define scale 26

char *convertToTitle(int n){
    /*
     * 替换发
     */
    char *title = (char *)malloc(length * sizeof(char));
    int tmp;
    int i = 0;
    /*
     * 除26，分别得到商和余数，若余数为0，则改为'Z',否则，改为'A'+余数-1,
     * 由于改为'Z'的时候，商也要从1变成0，因此n--
     */
    while(n){
        tmp = n % scale;
        n /= scale;
        if(tmp)
            title[i++] = tmp - 1 + 'A';
        else{
            title[i++] = 'Z';
            n--;
        }
    }
    title[i] = '\0';
    int left = 0;
    int right = i - 1;
    int temp;
    while(left < right){
        temp = title[left];
        title[left] = title[right];
        title[right] = temp;
        left++;
        right--;
    }
    return title;
}

int main(void){
    int n = 58;
    char *result = convertToTitle(n);
    return 0;
}
