#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define size_byte 8

uint32_t reverseBits(uint32_t n) {
    uint32_t temp = 1;
    int sum = 0;
    int length = size_byte * sizeof(uint32_t);
    while(n){
        sum = sum * 2 + (n & temp);
        n >>= temp;
        length--;
    }
    while(length){
        sum *= 2;
        length--;
    }
    return sum;
}

int main(void){
    uint32_t n = 43261596;
    uint32_t result = reverseBits(n);
    return 0;
}
