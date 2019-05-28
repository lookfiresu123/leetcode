#include <stdlib.h>
#include <stdbool.h>

bool isUgly(int num) {
    if (num < 1)
        return false;
    if (num == 1)
        return true;
    while (num % 2 == 0) {
        num = num / 2;
        if (num == 1)
            return true;
    }
    while (num % 3 == 0) {
        num = num / 3;
        if (num == 1)
            return true;
    }
    while (num % 5 == 0) {
        num = num / 5;
        if (num == 1)
            return true;
    }
    return false;
}

int main (void) {
    int num = 14;
    bool result = isUgly(num);
    return 0;
}
