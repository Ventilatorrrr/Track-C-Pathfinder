#include "../inc/libmx.h"

void mx_printint(int n) 
{
    if (n == -2147483648) 
    {
        write(1, "-2147483648", 11);
        return;
    }

    if (n == 0)
    {
        mx_printchar('0');
        return;
    }

    if (n < 0)
    {
        mx_printchar('-');
        n = -n;
    }

    char c[12];
    int i = 0;

    while (n != 0) 
    {
        c[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i > 0)
    {
        mx_printchar(c[--i]);
    }
}

