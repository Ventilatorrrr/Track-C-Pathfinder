#include "../inc/libmx.h"

int mx_list_size(t_list *list) 
{
    int count_size = 0;
    
    while (list != NULL) 
    {
        count_size++;
        list = list->next;
    }
    
    return count_size;
}
