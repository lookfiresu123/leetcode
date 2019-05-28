#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char* s) {
    char *p = s;
    int length = 0;
    int flag = 0;
    if(*s == '\0')
        return 0;
    while(*p != '\0') {
        p++;
    }
    p--;
    while(p >= s){
        if(*p == ' ' && flag == 0)
            p--;
        else if(*p != ' '){
            flag = 1;
            length++;
            p--;
        }
        else if(*p == ' ' && flag == 1)
            break;
    }
    return length;
}

int main(void){
    char *s = "hello world  ";
    int length = lengthOfLastWord(s);
    return 0;
}

