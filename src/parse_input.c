#include "pathfinder.h"

t_island *parse_input(char *file_content) {
    t_island *islands = NULL;
    char **lines = mx_strsplit(file_content, '\n');

    if (!lines) {
        mx_printerr("error: failed to split file content\n");
        exit(1);
    }

    if (!mx_isdigit(lines[0][0])) {
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        exit(1);
    }

    int expected_island_count = mx_atoi(lines[0]);
    if (expected_island_count <= 0) {
        mx_printerr("error: invalid number of islands\n");
        mx_del_strarr(&lines);
        exit(1);
    }

    int current_index = 0;  
    int actual_island_count = 0;  

    for (int i = 1; lines[i] != NULL; i++) {
        parse_line(&islands, lines[i], i + 1, &current_index);
        actual_island_count = get_island_count(islands); 
    }

    if (actual_island_count != expected_island_count) {
        mx_printerr("error: invalid number of islands\n");
        mx_clear_island_list(&islands);
        mx_del_strarr(&lines);
        exit(1);
    }

    mx_del_strarr(&lines);
    return islands;
}

