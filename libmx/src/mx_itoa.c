#include "../inc/libmx.h"

char *mx_itoa(int number) {
    if (number == 0) {
        char *zero = mx_strnew(1);
        zero[0] = '0';
        return zero;
    }

    if (number == INT_MIN) { 
        return mx_strdup("-2147483648"); 
    }

    int num = number;
    int sign = 0;  
    int size = 0;

    if (num < 0) {
        sign = 1;
        num = -num;
    }

    int temp = num;
    while (temp != 0) {
        temp /= 10;
        size++;
    }

    char *str = mx_strnew(size + sign);

    int i = 0;
    while (num != 0) {
        str[i++] = (num % 10) + '0';  
        num /= 10; 
    }

    if (sign) {
        str[i++] = '-';
    }

    mx_str_reverse(str);

    return str;
}
