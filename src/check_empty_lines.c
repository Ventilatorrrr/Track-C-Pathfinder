#include "pathfinder.h"

void check_empty_lines(const char *filename) {
    int file = open(filename, O_RDONLY);
    if (file < 0) {
        write(2, "Error opening file\n", 19);
        return;
    }

    char *buffer = malloc(1);
    char *line = malloc(256);
    if (!buffer || !line) {
        write(2, "Memory allocation error\n", 24);
        free(buffer);
        free(line);
        close(file);
        return;
    }

    int line_index = 0;
    int line_number = 1;

    while (read(file, buffer, 1) > 0) {
        if (*buffer == '\n' || line_index >= 255) {
            line[line_index] = '\0'; 
            if (is_empty_line(line)) {
                char *line_number_str = int_to_string(line_number);
                if (line_number_str) {
                    write(2, "Error: Empty line found at line ", 32);
                    write(2, line_number_str, mx_strlen(line_number_str)); 
                    write(2, "\n", 1);
                    free(line_number_str);
                }
                free(buffer);
                free(line);
                close(file);
                exit(1); 
            }
            line_index = 0;
            line_number++;
        } else {
            line[line_index++] = *buffer;
        }
    }

    free(buffer);
    free(line);
    close(file);
}
