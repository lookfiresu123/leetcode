/*
 * =====================================================================================
 *
 *       Filename:  add_digits.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月26日 15时29分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
int addDigits(int num) {
    if (num == 0)
        return 0;
    int result = num % 9;
    if (result == 0)
        return 9;
    return result;
}
