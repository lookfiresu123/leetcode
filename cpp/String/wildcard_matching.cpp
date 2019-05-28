#include <iostream>

using namespace std;

bool isMatch(char* s, char* p) {
    // 保存两个指针，其中star表示前一个'*'所在的位置，ss表示s中star所对应的子串的最后一个字符的位置
    const char* star=NULL;
    const char* ss=s;
    while (*s){
        // 当*p=='?'或*p==*s时，表示匹配当前字符
        if ((*p=='?') || (*p==*s)) { s++; p++; continue; }

        // 当*p=='*'时更新star和ss，表示若不匹配，则将star所对应的子串扩大到s的范围内再检查
        if (*p=='*') { star=p++; ss=s; continue; }  // ss=s表示此时*s包含在star所对应的子串范围内，为该子串的最后一个字符

        // 重新比较[star+1:]和[ss+1:]的元素
        if (star) { p = star+1; s=++ss; continue; }

       // 字符未匹配
        return false;
    }

    // 检查最后的p中是否只有'*'
    while (*p=='*') { p++; }

    return !*p; // 若此时*p=='\0'，则返回true，否则返回false
}
