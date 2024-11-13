#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) 
{
    if (nbr == 0) 
    {
        char *zero = mx_strnew(1);
        zero[0] = '0';
        return zero;
    }
    unsigned long q = nbr;
    int r, size = 0;
    unsigned long temp = nbr;
    while (temp != 0) 
    {
        size++;
        temp /= 16;
    }
    char *hex = mx_strnew(size);
    if (!hex) 
    {
        return NULL;  
    }
    int j = 0;
    while (q != 0) 
    {
        r = q % 16;
        if (r < 10)
            hex[j] = 48 + r; 
        else 
            hex[j] = 87 + r;  
        j++;
        q /= 16;
    }

    mx_str_reverse(hex);
    return hex;  
}
