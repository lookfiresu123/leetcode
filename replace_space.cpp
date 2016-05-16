#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

//length为牛客系统规定字符串输出的最大长度，固定为一个常数
class Solution {
public:
    void replaceSpace(char *str,int length) {
        char *p = str;
        char *arr = (char *)malloc((3 * length + 1) * sizeof(char));
        char *q = arr;
        while (*p != '\0') {
            if (*p == ' ') {
                *q++ = '%';
                *q++ = '2';
                *q++ = '0';
            } else
                *q++ = *p;
            ++p;
        }
        *q = '\0';
        strcpy(str, arr);
        free(arr);
    }
};

void print(char *s) {
    while (*s != '\0')
        cout << *s++;
    cout << endl;
}

int main() {
    char str[20] = {' ','a','b', ' ', '\0'};
    Solution sol;
    sol.replaceSpace(str, strlen(str));
    print(str);
    return 0;
}
