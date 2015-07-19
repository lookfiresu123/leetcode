#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define length_ascii 128

bool isIsomorphic(char* s, char* t) {
    char replace[length_ascii]; //one character of t can not be mapped by two character of s
    char replaced[length_ascii]; //one character of s can not map to two character of t
    int i;
    int length_s = 0;
    int length_t = 0;
    int temp;
    for(i=0;i<length_ascii;i++){
        replace[i] = '\0';
        replaced[i] = '\0';
    }
    //get the length of s and t
    while(s[length_s])
        length_s++;
    while(t[length_t])
        length_t++;
    if(length_s != length_t)
        return false;
    for(i=0;i<length_s;i++){
        temp = (int)s[i];
        if(replaced[temp] == '\0')
            replaced[temp] = t[i];
        else{
            if(replaced[temp] != t[i])
                return false;
        }
        temp = (int)t[i];
        if(replace[temp] == '\0')
            replace[temp] = s[i];
        else{
             if(replace[temp] != s[i])
                return false;
        }
    }
    return true;
}

int main(void){
    char *s = "paperp";
    char *t = "titles";
    bool result = isIsomorphic(s,t);
     return 0;
}


