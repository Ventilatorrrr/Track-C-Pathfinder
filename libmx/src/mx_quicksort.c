#include "../inc/libmx.h"

int mx_quicksort(char **array, int start, int end) {
    if (!array) {
        return -1; 
    }

    int swap_count = 0; 

    if (start < end) {
        int left = start;
        int right = end;

        int pivot_index = (start + end) / 2; 
        int pivot_value_length = mx_strlen(array[pivot_index]);

        while (left <= right) {
            while (mx_strlen(array[left]) < pivot_value_length) {
                left++;
            }
            while (mx_strlen(array[right]) > pivot_value_length) {
                right--;
            }

            if (left <= right) {
                if (left != right && mx_strlen(array[left]) != mx_strlen(array[right])) {
                  
                    char *temp = array[left];
                    array[left] = array[right];
                    array[right] = temp;
                    swap_count++; 
                }
                left++;
                right--;
            }
        }

        swap_count += mx_quicksort(array, start, right); 
        swap_count += mx_quicksort(array, left, end); 
    }

    return swap_count; 
}
