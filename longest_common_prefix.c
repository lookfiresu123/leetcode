#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
        return "";
    int i,j;
    int new_length;
    int length = strlen(strs[0]);
    char *result = (char *)malloc((length+1) * sizeof(char));
    for(i = 0;i <= length;i++)
        result[i] = strs[0][i];
    for(i = 1;i < strsSize;i++){
        new_length = strlen(strs[i]);
        length = length < new_length ? length : new_length;
        for(j = 0;j < length;j++){
            if(result[j] != strs[i][j])
                break;
        }
        length = j;
        if(length == 0)
            return "";
    }
    char *final_result = (char *)malloc((length+1) * sizeof(char));
    for(i = 0;i < length;i++)
        final_result[i] = result[i];
    final_result[i] = '\0';
    free(result);
    return final_result;
}

int main(void){
    char *strs[] = {"hello world","hello","hey guys","how are you"};
    int strsSize = 4;
    char *final_result = longestCommonPrefix(strs,strsSize);
    return 0;
}
