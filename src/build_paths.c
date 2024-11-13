#include "pathfinder.h"

void build_paths(t_list **prev, int start, int current, int *dist, t_route **routes) {
   
    int frame_capacity = 10;
    Frame *frames = malloc(frame_capacity * sizeof(Frame));
    if (frames == NULL) {
        mx_printerr("Error: Failed to allocate memory for frames\n");
        return;
    }

    int path_capacity = 10;
    int *path = malloc(path_capacity * sizeof(int));
    if (path == NULL) {
        mx_printerr("Error: Failed to allocate memory for path\n");
        free(frames);
        return;
    }

    int frame_size = 0; 
    int length = 0;      

    frames[frame_size++] = (Frame){current, 0};

    while (frame_size > 0) {
        if (frame_size > frame_capacity) {
            frame_capacity *= 2;
            frames = realloc(frames, frame_capacity * sizeof(Frame));
            if (frames == NULL) {
                mx_printerr("Error: Failed to reallocate memory for frames\n");
                free(path);
                return;
            }
        }

        Frame frame = frames[--frame_size];
        current = frame.current;
        length = frame.length;

        
        if (length >= path_capacity) {
            path_capacity *= 2;
            path = realloc(path, path_capacity * sizeof(int));
            if (path == NULL) {
                mx_printerr("Error: Failed to reallocate memory for path\n");
                free(frames);
                return;
            }
        }

        path[length++] = current;

       
        if (current == start) {
            int *full_path = malloc(sizeof(int) * length);
            if (full_path == NULL) {
                mx_printerr("Error: Failed to allocate memory for full_path\n");
                break;
            }

            for (int i = 0; i < length; i++) {
                full_path[i] = path[length - i - 1];
            }

            t_route *new_route = add_route(full_path, length, dist[current], routes);
            if (new_route == NULL) {
                mx_printerr("Error: Failed to add route\n");
            }

            free(full_path); 
            length--;
            continue;
        }


        for (t_list *pred = prev[current]; pred != NULL; pred = pred->next) {
            if (frame_size >= frame_capacity) {
                frame_capacity *= 2;
                frames = realloc(frames, frame_capacity * sizeof(Frame));
                if (frames == NULL) {
                    mx_printerr("Error: Failed to reallocate memory for frames\n");
                    free(path);
                    return;
                }
            }
            frames[frame_size++] = (Frame){*((int *)pred->data), length};
        }

        length--;
    }


    free(frames);
    free(path);
}

