#include "pathfinder.h"

void check_file_format(char *file_content) 
{
    char **lines = mx_strsplit(file_content, '\n');
    if (!lines || !lines[0]) {
        mx_printerr("error: file is empty or unreadable\n");
        mx_del_strarr(&lines);
        exit(1);
    }

    if (mx_strlen(lines[0]) == 0) {
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        exit(1);
    }

    
    if (!is_only_digits(lines[0]) || (lines[0][0] == '0' && mx_strlen(lines[0]) > 1)) {
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        exit(1);
    }

    int island_count = mx_atoi(lines[0]);
    if (island_count <= 0) {
        mx_printerr("error: line 1 is not valid\n");
        mx_del_strarr(&lines);
        exit(1);
    }

  for (int i = 1; lines[i]; i++) {
       
        if (mx_strlen(lines[i]) == 0 || mx_isspace(lines[i][0])) {
            mx_printerr("error: line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr(" is empty or contains only whitespace\n");
            mx_del_strarr(&lines);
            exit(1);
        }


        if (!mx_strchr(lines[i], '-') || !mx_strchr(lines[i], ',')) {
            mx_printerr("error: line ");
            char *line_num = mx_itoa(i + 1); 
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr(" is not valid\n");
            mx_del_strarr(&lines);
            exit(1);
        }

        char *line = lines[i];
        char *dash_pos = mx_strchr(line, '-');
        char *comma_pos = mx_strchr(line, ',');

        if (!dash_pos || !comma_pos || dash_pos > comma_pos) {
            mx_printerr("error: line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr(" is not valid\n");
            mx_del_strarr(&lines);
            exit(1);
        }

        int first_len = dash_pos - line;
        int second_len = comma_pos - dash_pos - 1;
        char *distance_str = comma_pos + 1;

        if (first_len <= 0 || second_len <= 0 || !mx_isdigit(distance_str[0])) {
            mx_printerr("error: line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr(" is not valid\n");
            mx_del_strarr(&lines);
            exit(1);
        }

        char *first_island = mx_strndup(line, first_len);
        char *second_island = mx_strndup(dash_pos + 1, second_len);
        if (!first_island || !second_island) {
            mx_printerr("error: memory allocation failed\n");
            mx_strdel(&first_island);
            mx_strdel(&second_island);
            mx_del_strarr(&lines);
            exit(1);
        }

      
        if (mx_strcmp(first_island, second_island) == 0) {
            mx_printerr("error: line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr(" is not valid: identical islands\n");
            mx_strdel(&first_island);
            mx_strdel(&second_island);
            mx_del_strarr(&lines);
            exit(1);
        }

        if (!is_only_letters(first_island) || !is_only_letters(second_island)) {
            mx_printerr("error: line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr(" is not valid: invalid island name\n");
            mx_strdel(&first_island);
            mx_strdel(&second_island);
            mx_del_strarr(&lines);
            exit(1);
        }

        if (!is_only_digits(distance_str)) {
            mx_printerr("error: invalid distance in line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr("\n");
            mx_strdel(&first_island);
            mx_strdel(&second_island);
            mx_del_strarr(&lines);
            exit(1);
        }

        int distance = mx_atoi(distance_str);
        if (distance <= 0) {
            mx_printerr("error: invalid distance in line ");
            char *line_num = mx_itoa(i + 1);
            mx_printerr(line_num);
            mx_strdel(&line_num);
            mx_printerr("\n");
            mx_strdel(&first_island);
            mx_strdel(&second_island);
            mx_del_strarr(&lines);
            exit(1);
        }

        mx_strdel(&first_island);
        mx_strdel(&second_island);
    }

    mx_del_strarr(&lines);
}

