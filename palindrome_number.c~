#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define size_int 32

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int store = x;
    int temp[size_int],i;
    for(i=0;i<size_int;i++)
        temp[i] = -1;
    i = 0;
    while(temp[i] = x % 10,x /= 10,temp[i++] != 0 || x != 0)
        ;
    i--;
    int j,sum = 0;
    for(j=0;j<i;j++)
        sum = sum*10 + temp[j];
    if(store == sum)
        return true;
    else
        return false;
}

int main(){
    int x;
    printf("input a num\n");
    scanf("%d",&x);
    if(isPalindrome(x))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
