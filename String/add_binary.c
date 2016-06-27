#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int length_a = strlen(a);
    int length_b = strlen(b);
    int length_result = length_a > length_b ? length_a : length_b;
    int *result = (int *)malloc((length_result + 1) * sizeof(int));

    int *temp_a = (int *)malloc(length_result * sizeof(int));
    int *temp_b = (int *)malloc(length_result * sizeof(int));
    int i = 0, j = 0;
    int radical_a = length_result - length_a;
    int radical_b = length_result - length_b;

    // fill temp_a
    j = length_result - 1;
    i = radical_a;
    while (i-- > 0)
        temp_a[j--] = 0;
    for (i = 0 ; i < length_a ; i++)
        temp_a[j--] = a[i] - '0';

    // fill temp_b
    j = length_result - 1;
    i = radical_b;
    while (i-- > 0)
        temp_b[j--] =0;
    for (i = 0 ; i < length_b ; i++)
        temp_b[j--] = b[i] - '0';

    int carry_bit = 0;      // 进位符
    int temp;
    for (i = 0 ; i < length_result ; i++) {
        temp = temp_a[i] + temp_b[i] + carry_bit;
        result[i] = temp % 2;
        carry_bit = temp / 2;
    }
    result[length_result] = carry_bit;
    char *result_final;

    if (result[length_result] == 0) {
        result_final = (char *)malloc((length_result + 1) * sizeof(char));
        for (i = length_result - 1, j = 0 ; i >= 0 ; i--, j++)
            result_final[j] = result[i] + '0';
        result_final[j] = '\0';
    }
    else {
        result_final = (char *)malloc((length_result + 2) * sizeof(char));
        for (i = length_result, j = 0 ; i >= 0 ; i--, j++)
            result_final[j] = result[i] + '0';
        result_final[j] = '\0';
    }

    free(result);
    free(temp_a);
    free(temp_b);

    return result_final;
}

int main (void) {
    char *a = "10000011";
    char *b = "111000";
    char *result = addBinary(a, b);
    return 0;
}
