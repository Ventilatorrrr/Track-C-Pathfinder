#include "pathfinder.h"

void check_duplicate_bridges(t_island *islands) {
    t_list *bridge_keys = NULL;

    for (t_island *island = islands; island != NULL; island = island->next) {
        for (t_path *path = island->path; path != NULL; path = path->nextPath) {
         
            if (mx_strcmp(island->name, path->nextConnect->name) < 0) {
                char *key = create_bridge_key(island->name, path->nextConnect->name);

                if (is_bridge_duplicate(bridge_keys, key)) {
                    write(2, "error: duplicate bridges\n", 25);
                    free(key);
                    mx_clear_list(&bridge_keys);
                    exit(1);
                } else {
                    t_list *new_node = malloc(sizeof(t_list));
                    new_node->data = key;
                    new_node->next = bridge_keys;
                    bridge_keys = new_node;
                }
            }
        }
    }

    mx_clear_list(&bridge_keys);
}

