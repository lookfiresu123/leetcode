#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define length_version 1000

#define difference(x,y) x > y ? x-y : y-x
//#define find_min(x,y) x < y ? x : y

int cal_nums_contain(char *str){
    int nums_str_contain = 0;
    char *p = str;
    while(*p){
        if(*p == '.')
            nums_str_contain++;
        p++;
    }
    return nums_str_contain;
}

/* add n contains */
char *add_contain_n(char *str,int n){
    char *result = (char *)malloc(length_version * sizeof(char));
    char *p = str;
    char *q = result;
    while(*p){
        *q = *p;
        p++;
        q++;
    }
    int i;
    for(i=0;i<n;i++){
        *q++ = '.';
        *q++ = '0';
    }
    *q = '\0';
    return result;
}

/* find nums of digits between a pair of '.' */
/*
 * for example: "xxxx.axxx.xxx"
 *                    ^   ^
 *                    |   |
 *                  start end
 */
int find_nums_between_contains(char *start,char *end){
    char *p;
    int nums = 0;
    for(p=start;p<end;p++)
        nums++;
    return nums;
}

/*
 * this function means add characters of digits '0' between a pair nearly '.'
 * and return ends before next '.'
 * @char *start_dest: the address that start_dest to add digits and end before next '.'
 * @int n: how many characters of digits '0' that should to be added
 */
char *add_digits_n(char *start_dest,int n){
    int i;
    for(i=0;i<n;i++)
        *start_dest++ = '0';
    return start_dest;
}

char *add_remain(char *start_dest,char *start_source,char *end_source){
    char *p = start_source;
    while(p <= end_source){
        *start_dest = *p;
        start_dest++;
        p++;
    }
    return start_dest;
}

void adapt_for_digits(char *str1, char *str2,char *format_version1,char *format_version2){
    char *start_str1 = str1;
    char *start_str2 = str2;
    char *p_format1 = format_version1;
    char *p_format2 = format_version2;
    int n_str1;
    int n_str2;
    int flag_1 = 1;
    int flag_2 = 1;
    while(*str1 != '\0' || *str2 != '\0'){
        if(*str1 == '.' || !(*str1)){
            n_str1 = find_nums_between_contains(start_str1,str1);
            //start_str1 = str1 + 1;
            flag_1 = 0;
        }
        if(*str2 == '.' || !(*str2)){
            n_str2 = find_nums_between_contains(start_str2,str2);
            //start_str2 = str2 + 1;
            flag_2 = 0;
        }
        /* deal with digits */
        if((!flag_1) && (!flag_2)){
            if(n_str1 > n_str2){
                p_format2 = add_digits_n(p_format2,n_str1-n_str2);
                p_format1 = add_remain(p_format1,start_str1,str1);
                p_format2 = add_remain(p_format2,start_str2,str2);
                flag_1 = 1;
                flag_2 = 1;
                start_str1 = str1 + 1;
                start_str2 = str2 + 1;
            }
            else{
                p_format1 = add_digits_n(p_format1,n_str2-n_str1);
                p_format1 = add_remain(p_format1,start_str1,str1);
                p_format2 = add_remain(p_format2,start_str2,str2);
                flag_1 = 1;
                flag_2 = 1;
                start_str1 = str1 + 1;
                start_str2 = str2 + 1;
            }
        }
        if(flag_1)
            str1++;
        if(flag_2)
            str2++;
    }
    //add the last
    n_str1 = find_nums_between_contains(start_str1,str1);
    n_str2 = find_nums_between_contains(start_str2,str2);
    if(n_str1 > n_str2){
        p_format2 = add_digits_n(p_format2,n_str1-n_str2);
        p_format1 = add_remain(p_format1,start_str1,str1);
        p_format2 = add_remain(p_format2,start_str2,str2);
    }
    else{
        p_format1 = add_digits_n(p_format1,n_str2-n_str1);
        p_format1 = add_remain(p_format1,start_str1,str1);
        p_format2 = add_remain(p_format2,start_str2,str2);
    }
}

int compare(char *str1,char *str2){
    //insurance: promise that str1 = str2
    int length_1 = 0;
    int length_2 = 0;
    char *p_1 = str1;
    char *p_2 = str2;
    int i;
    while(*p_1){
        length_1++;
        p_1++;
    }
    while(*p_2){
        length_2++;
        p_2++;
    }
    if(length_1 != length_2)
        printf("length error: format_version1 is not equal to format_version2\n");
    else{
        for(i=0;i<length_1;i++){
            if(str1[i] > str2[i])
                return 1;
            else if(str1[i] < str2[i])
                return -1;
        }
    }
    return 0;
}

int compareVersion(char *version1, char *version2) {
    /*
     * cal the sum of '.' of each version
     */
    int nums_version1_contain = cal_nums_contain(version1);
    int nums_version2_contain = cal_nums_contain(version2);

    /* adapt the format of '.' */
    int nums_contain_added = difference(nums_version1_contain,nums_version2_contain);// how many '.' will be added
    char *version_to_be_adapted;
    if(nums_version1_contain > nums_version2_contain)//which version should to be adapted
        version_to_be_adapted = version2;
    else
        version_to_be_adapted = version1;
    char *after_add_contain_version1 = version1;
    char *after_add_contain_version2 = version2;
    if(version_to_be_adapted == version1)
        after_add_contain_version1 = add_contain_n(version_to_be_adapted,nums_contain_added);//add '.' for adapt
    else
        after_add_contain_version2 = add_contain_n(version_to_be_adapted,nums_contain_added);//add '.' for adapt
    /* adapt the format of digits character */
    char *format_version1 = (char *)malloc(length_version * sizeof(char));
    char *format_version2 = (char *)malloc(length_version * sizeof(char));
    adapt_for_digits(after_add_contain_version1,after_add_contain_version2,format_version1,format_version2);

    //compare version1 and version2 by format_version1 and format_version2
    int result = compare(format_version1,format_version2);
    return result;
}

int main(void){
    char *version1 = "1.00000000000000000000001";
    char *version2 = "1.10";
    int result = compareVersion(version1,version2);
    return 0;
}
