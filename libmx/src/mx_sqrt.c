#include "../inc/libmx.h"

int mx_sqrt(int x) 
{
    if (x < 0) {
        return 0;
    }
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 1;
    int right = x;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (mid * mid == x) {
            return mid;
        } 
        else if (mid * mid < x) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return 0;
}

