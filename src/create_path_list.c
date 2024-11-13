#include "pathfinder.h"

t_path *create_path_list(int *pathIDs, int *pathDistances, t_island **connectedIslands, int count) {
    if (count <= 0 || pathIDs == NULL || pathDistances == NULL || connectedIslands == NULL) {
        return NULL; 
    }

    t_path *head = NULL; 
    t_path *current = NULL; 

    for (int i = 0; i < count; i++) {
        t_path *new_path = (t_path *)malloc(sizeof(t_path));
        if (!new_path) {
            
            mx_clear_path_list(&head);
            return NULL;
        }

       
        new_path->pathID = pathIDs[i];
        new_path->pathDistance = pathDistances[i];
        new_path->nextConnect = connectedIslands[i];
        new_path->nextPath = NULL;

       
        if (head == NULL) {
            head = new_path; 
        } else {
            current->nextPath = new_path; 
        }
        current = new_path; 
    }

    return head; 
}


