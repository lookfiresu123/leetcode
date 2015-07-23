#include<stdio.h>
#include<stdlib.h>

#define scale 26

int titleToNumber(char* s) {
    int number = 0;
    char *p = s;
    while(*p){
        number = scale * number + *p + 1 -'A';
        p++;
    }
    return number;
}

int main(void){
    char *s = "AA";
    int number = titleToNumber(s);
    return 0;
}
