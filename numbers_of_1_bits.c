#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int hammingWeight(uint32_t n) {
    int sum = 0;
    uint32_t temp = 1;
    while(n != 0){
        if(n & temp)
            sum ++;
        n >>= temp;
    }
    return sum;
}

int main(void){
    uint32_t n = 16;
    int sum = hammingWeight(n);
    return 0;
}
