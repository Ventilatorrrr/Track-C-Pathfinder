#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || lst->next == NULL) {
        return lst;  
    }

    t_list *sorted = NULL;  
    t_list *current = lst;  

    while (current != NULL) {
        t_list *next = current->next; 
        if (sorted == NULL || cmp(current->data, sorted->data)) {
            current->next = sorted;  
            sorted = current;   
        } else {
            t_list *temp = sorted;  
            while (temp->next != NULL && cmp(temp->next->data, current->data)) {
                temp = temp->next;  
            }
            current->next = temp->next;  
            temp->next = current; 
        }
        current = next;  
    }

    return sorted;  
}

