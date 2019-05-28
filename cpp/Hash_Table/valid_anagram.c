#include <stdlib.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    if (!s || !t) {
        if (!s && !t)
            return true;
        return false;
    }
    int count_alpha[26];
    // set zero
    int i;
    for (i = 0 ; i < 26 ; i++)
        count_alpha[i] = 0;

    // set count_alpha
    while (*s != '\0') {
        count_alpha[*s - 'a']++;
        s++;
    }
    // match count_alpha
    while (*t != '\0') {
        count_alpha[*t - 'a']--;
        t++;
    }
    // check count_alpha
    for (i = 0 ; i < 26 ; i++) {
        if (count_alpha[i] != 0)
            return false;
    }
    return true;
}
