#include "pathfinder.h"

void parse_line(t_island **islands, char *line, int line_number, int *current_index) {
    char *line_copy = mx_strdup(line);
    char *island1_name = mx_strtok(line_copy, "-");
    char *island2_name = mx_strtok(NULL, ",");
    char *distance_str = mx_strtok(NULL, "\0");

    if (!island1_name || !island2_name || !distance_str) {
        mx_printerr("error: invalid format in line ");
        char *line_num_str = mx_itoa(line_number);
        mx_printerr(line_num_str);
        mx_strdel(&line_num_str);
        mx_printerr("\n");
        mx_strdel(&line_copy);
        exit(1);
    }

  
    if (!is_only_letters(island1_name) || !is_only_letters(island2_name)) {
        mx_printerr("error: invalid island name in line ");
        char *line_num_str = mx_itoa(line_number);
        mx_printerr(line_num_str);
        mx_strdel(&line_num_str);
        mx_printerr("\n");
        mx_strdel(&line_copy);
        exit(1);
    }

   
    for (int i = 0; distance_str[i] != '\0'; i++) {
        if (!mx_isdigit(distance_str[i])) {
            mx_printerr("error: invalid distance format in line ");
            char *line_num_str = mx_itoa(line_number);
            mx_printerr(line_num_str);
            mx_strdel(&line_num_str);
            mx_printerr("\n");
            mx_strdel(&line_copy);
            exit(1);
        }
    }

    int distance = mx_atoi(distance_str);
    if (distance <= 0) {
        mx_printerr("error: invalid bridge length in line ");
        char *line_num_str = mx_itoa(line_number);
        mx_printerr(line_num_str);
        mx_strdel(&line_num_str);
        mx_printerr("\n");
        mx_strdel(&line_copy);
        exit(1);
    }

    add_bridge(islands, island1_name, island2_name, distance, current_index);

    mx_strdel(&line_copy);
}

