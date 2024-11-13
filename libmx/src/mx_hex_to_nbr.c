#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) 
{
    if (hex == NULL) {
        return 0;
    }

    int len = 0;
    while (hex[len] != '\0') {
        len++;
    }

    unsigned long res = 0; 
    unsigned long dec = 1;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            res += (hex[i] - '0') * dec;
        }
        else if ((hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= 'a' && hex[i] <= 'f')) {
            res += ((hex[i] & 0xDF) - 55) * dec; 
        } else {
            return 0; 
        }

        dec *= 16; 
    }

    return res;
}
