#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 1000

int delete_zero(int x){
    int y=0,z,i=0,j,temp=1;
    while(z = x % 10,x /= 10,(x != 0)||(z != 0)){
        if(z != 0){
            temp = 1;
            for(j=0;j<i;j++)
                temp *= 10;
            y += z*temp;
            i++;
        }
    }
    return y;
}

int make_happy(int y){
    int x = 0,z;
    while((z = y % 10) != 0){
        x += z*z;
        y /= 10;
    }
    return x;
}

bool isHappy(int n) {
    //每次循环都把结果中的0去掉
    int x = n,y;
    int store[max];
    int i;
    for(i=0;i<max;i++)
        store[i] = -1;
    //store[0] = x;
    while(x != 1){
        i = 0;
        while(store[i] != -1){
            if(store[i] == x)
                return false;
            i++;
        }
        store[i] = x;
        y = delete_zero(x);//去掉x中的0
        x = make_happy(y);//y中已经没有0
    }
    return true;
}

int main(void){
    int x;
    printf("input for x\n");
    scanf("%d",&x);
    if(isHappy(x))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
