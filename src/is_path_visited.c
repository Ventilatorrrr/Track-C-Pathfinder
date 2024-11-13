#include "pathfinder.h"

bool is_path_visited(t_visited_path *visited, const char *from, const char *to) {
    char *direct = mx_strjoin(from, to);
    char *reverse = mx_strjoin(to, from);
    bool visited_found = false;

    while (visited) {
        if (mx_strcmp(visited->path, direct) == 0 || mx_strcmp(visited->path, reverse) == 0) {
            visited_found = true;
            break;
        }
        visited = visited->next;
    }

    mx_strdel(&direct);
    mx_strdel(&reverse);
    return visited_found;
}
