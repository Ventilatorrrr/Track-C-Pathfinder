#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int res = 0;
    int i = 0;
    int sign = 1;

    while (mx_isspace(str[i])) {
        i++;
    }

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    while (mx_isdigit(str[i])) {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return res * sign; 
}

