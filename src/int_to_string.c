#include "pathfinder.h"

char *int_to_string(int num) {
    int length = 1;
    int temp = num;

    while (temp /= 10) {
        length++;
    }

    char *str = malloc(length + 1);
    if (!str) return NULL;

    str[length] = '\0';
    while (length--) {
        str[length] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}
